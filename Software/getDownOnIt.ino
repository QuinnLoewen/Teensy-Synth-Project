#include <Audio.h>
#include <USBHost_t36.h>
#include <math.h>

#define DEBUG_ADSR 1

// --- Constants and Macros ---
constexpr byte MAX_POLYPHONY  = 8;
constexpr byte MAX_WAVEFORMS  = 8;
constexpr byte MIN_MIDI_NOTE  = 24;    // note > 23
constexpr byte MAX_MIDI_NOTE  = 107;   // note < 108
constexpr float DIV127        = (1.0f / 127.0f);
constexpr int OCTAVE_SHIFT    = 12;
constexpr unsigned long DEBOUNCE_DELAY = 100; // ms
constexpr byte BUFFER_SIZE = 8;

// --- Precomputed Detune Multipliers (reduced values) ---
const float detuneFactors[MAX_POLYPHONY] = {
  1.0,
  1.0005776,   // +1 cent
  0.9994224,   // -1 cent
  1.0011552,   // +2 cents
  0.9988448,   // -2 cents
  1.0017328,   // +3 cents
  0.9982672,   // -3 cents
  1.0023104    // +4 cents
};

// --- Precomputed MIDI Note Frequencies ---
const float noteFreqs[128] = {
  8.176, 8.662, 9.177, 9.723, 10.301, 10.913, 11.562, 12.25,
  12.978, 13.75, 14.568, 15.434, 16.352, 17.324, 18.354, 19.445,
  20.602, 21.827, 23.125, 24.5, 25.957, 27.5, 29.135, 30.868,
  32.703, 34.648, 36.708, 38.891, 41.203, 43.654, 46.249, 48.999,
  51.913, 55, 58.27, 61.735, 65.406, 69.296, 73.416, 77.782,
  82.407, 87.307, 92.499, 97.999, 103.826, 110, 116.541, 123.471,
  130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998,
  207.652, 220, 233.082, 246.942, 261.626, 277.183, 293.665, 311.127,
  329.628, 349.228, 369.994, 391.995, 415.305, 440, 466.164, 493.883,
  523.251, 554.365, 587.33, 622.254, 659.255, 698.456, 739.989, 783.991,
  830.609, 880, 932.328, 987.767, 1046.502, 1108.731, 1174.659, 1244.508,
  1318.51, 1396.913, 1479.978, 1567.982, 1661.219, 1760, 1864.655, 1975.533,
  2093.005, 2217.461, 2349.318, 2489.016, 2637.02, 2793.826, 2959.955, 3135.963,
  3322.438, 3520, 3729.31, 3951.066, 4186.009, 4434.922, 4698.636, 4978.032,
  5274.041, 5587.652, 5919.911, 6271.927, 6644.875, 7040, 7458.62, 7902.133,
  8372.018, 8869.844, 9397.273, 9956.063, 10548.08, 11175.3, 11839.82, 12543.85
};

inline bool isValidMidiNote(byte note) {
  return note >= MIN_MIDI_NOTE && note <= MAX_MIDI_NOTE;
}

// --- USB MIDI Setup ---
USBHost myusb;
USBHub hub1(myusb);
MIDIDevice midi1(myusb);

// --- Global Variables ---
byte globalNote = 0;
byte globalVelocity = 0;
byte activeNotes[MAX_POLYPHONY] = {0};
bool keyState[128] = {false};
byte roundRobinIndex = 0;

byte keyBuffer[BUFFER_SIZE];
byte keyBufferSize = 0;

// --- Arpeggiator Globals ---
byte arpNotes[BUFFER_SIZE] = {0};  // live chord (notes held)
byte arpCount = 0;
byte currentArpIndex = 0;
unsigned long lastArpTime = 0;
unsigned long cycleStartTime = 0;
byte previousStep = 255;
byte frozenArpNotes[BUFFER_SIZE] = {0};
byte frozenArpCount = 0;

// --- Potentiometer Pins ---
const int potAttack   = A17;
const int potDecay    = A16;
const int potSustain  = A15;
const int potRelease  = A14;
const int potLFOSpeed = A10;
const int potLFODepth = A11;

// --- Button Pins ---
// Mode change and waveform change buttons.
const int modeButtonPin = 33;
const int waveChangeButtonPin = 35;
// New effect button.
const int effectButtonPin = 36;
bool lastModeButtonState = LOW;
bool lastWaveButtonState = LOW;
bool lastEffectButtonState = LOW;

// --- Global LFO Variables ---
float LFOdepth = 0.0f;
float LFOspeed = 0.0f;

// --- Audio Objects ---
AudioSynthWaveform polyWaves[MAX_WAVEFORMS];
AudioEffectEnvelope polyEnvs[MAX_WAVEFORMS];

AudioSynthWaveform snapBackWave, snapBackWaveStack;
AudioSynthWaveformModulated snapBackMod;
AudioEffectEnvelope snapBackEnv;

AudioMixer4 polyMix1, polyMix2, snapBackMix, PolyMasterMix, BigMasterMixer;
AudioSynthWaveform LFO;
AudioOutputI2S audioOut;
AudioControlSGTL5000 audioShield;

// --- New Effect Object ---
// We'll use a delay effect as our global effect.
AudioEffectDelay delayEffect;

// --- Patch Cord Connections ---
// Note: We remove the direct connection from BigMasterMixer to audioOut and insert delayEffect.
AudioConnection patchCordPolyEnv0(polyWaves[0], polyEnvs[0]);
AudioConnection patchCordPolyEnv1(polyWaves[1], polyEnvs[1]);
AudioConnection patchCordPolyEnv2(polyWaves[2], polyEnvs[2]);
AudioConnection patchCordPolyEnv3(polyWaves[3], polyEnvs[3]);
AudioConnection patchCordPolyEnv4(polyWaves[4], polyEnvs[4]);
AudioConnection patchCordPolyEnv5(polyWaves[5], polyEnvs[5]);
AudioConnection patchCordPolyEnv6(polyWaves[6], polyEnvs[6]);
AudioConnection patchCordPolyEnv7(polyWaves[7], polyEnvs[7]);

AudioConnection patchCordSnapBack1(snapBackWave, 0, snapBackMix, 0);
AudioConnection patchCordSnapBack2(snapBackWave, 0, snapBackMod, 0);
AudioConnection patchCordSnapBack3(snapBackWaveStack, 0, snapBackMix, 1);
AudioConnection patchCordSnapBack4(snapBackMod, 0, snapBackMix, 2);

AudioConnection patchCordPolyMix1(polyEnvs[0], 0, polyMix1, 0);
AudioConnection patchCordPolyMix2(polyEnvs[1], 0, polyMix1, 1);
AudioConnection patchCordPolyMix3(polyEnvs[2], 0, polyMix1, 2);
AudioConnection patchCordPolyMix4(polyEnvs[3], 0, polyMix1, 3);
AudioConnection patchCordPolyMix5(polyEnvs[4], 0, polyMix2, 0);
AudioConnection patchCordPolyMix6(polyEnvs[5], 0, polyMix2, 1);
AudioConnection patchCordPolyMix7(polyEnvs[6], 0, polyMix2, 2);
AudioConnection patchCordPolyMix8(polyEnvs[7], 0, polyMix2, 3);

AudioConnection patchCordPolyMaster1(polyMix1, 0, PolyMasterMix, 0);
AudioConnection patchCordPolyMaster2(polyMix2, 0, PolyMasterMix, 1);
AudioConnection patchCordSnapBackEnv(snapBackMix, 0, snapBackEnv, 0);
AudioConnection patchCordBigMaster1(snapBackEnv, 0, BigMasterMixer, 1);
AudioConnection patchCordBigMaster2(PolyMasterMix, 0, BigMasterMixer, 0);

// Instead of direct connection to audioOut, route BigMasterMixer through delayEffect.
AudioConnection patchCordDelay(BigMasterMixer, 0, delayEffect, 0);
AudioConnection patchCordDelayOut(delayEffect, 0, audioOut, 1);
// The LFO output remains connected to audioOut on channel 0.
AudioConnection patchCordAudioOut2(LFO, 0, audioOut, 0);

// --- Global Waveform Variables ---
// This global waveform is shared by all modes.
const int waveformTypes[] = {WAVEFORM_SINE, WAVEFORM_SQUARE, WAVEFORM_TRIANGLE, WAVEFORM_SAWTOOTH};
const int numWaveforms = sizeof(waveformTypes) / sizeof(waveformTypes[0]);
// Set default waveform to sawtooth (index 3).
int currentWaveformIndex = 3;

// --- State Machine Definitions ---
enum ModeState { POLY_MODE, SNAP_MODE, ARP_MODE };
ModeState currentState;
bool modeInitialized = false;

// --- Effect State ---
bool effectEnabled = false;  // global effect toggle

// --- Function Prototypes ---
void setUpAudio();
void setUpUSBMidi();
void initLFO();
void USBTaskRead();

void enterPolyMode();
void enterSnapMode();
void enterArpMode();

void updatePolyMode();
void updateSnapMode();
void updateArpMode();

void activatePolyphonicMode();
void activateSnapBackMode();
void activateArpeggiatorMode();

void updateStateMachine();
void checkWaveformChange();
void updateEffect();

void ADSRUpdate();
void LFOUpdate();
void changeWaveform(int waveformType);
void clearAllNotes();

void addArpNote(byte note);
void removeArpNote(byte note);

void myNoteOn(byte channel, byte note, byte velocity);
void myNoteOff(byte channel, byte note, byte velocity);

void keyBuff(byte note, bool noteOn);
void playPolyNote(byte note);
void stopPolyNote(byte note);

void oscPlay(byte note);
void oscStop();

// --- Setup Function ---
void setup() {
  pinMode(modeButtonPin, INPUT_PULLUP);
  pinMode(waveChangeButtonPin, INPUT_PULLUP);
  pinMode(effectButtonPin, INPUT_PULLUP);
  Serial.begin(9600);
  
  setUpAudio();
  setUpUSBMidi();
  initLFO();
  
  // Set the global waveform once at startup.
  changeWaveform(waveformTypes[currentWaveformIndex]);
  
  // Start in Poly Mode.
  currentState = POLY_MODE;
  enterPolyMode();
}

// --- Main Loop ---
void loop() {
  USBTaskRead();
  updateStateMachine();   // Handle mode switching via mode button.
  checkWaveformChange();  // Handle waveform change requests.
  updateEffect();         // Handle effect button and update effect parameters.
  
  // Update the current mode.
  switch (currentState) {
    case POLY_MODE:
      updatePolyMode();
      break;
    case SNAP_MODE:
      updateSnapMode();
      break;
    case ARP_MODE:
      updateArpMode();
      break;
  }
  
  ADSRUpdate();
  LFOUpdate();
}

// --- State Machine Functions ---
void updateStateMachine() {
  bool newModeButtonState = digitalRead(modeButtonPin);
  if (newModeButtonState == HIGH && lastModeButtonState == LOW) {
    delay(DEBOUNCE_DELAY);
    // Cycle through modes.
    if (currentState == POLY_MODE)
      currentState = SNAP_MODE;
    else if (currentState == SNAP_MODE)
      currentState = ARP_MODE;
    else
      currentState = POLY_MODE;
    
    clearAllNotes();
    
    // Enter new mode.
    switch (currentState) {
      case POLY_MODE: enterPolyMode(); break;
      case SNAP_MODE: enterSnapMode(); break;
      case ARP_MODE:  enterArpMode(); break;
    }
    Serial.print("Mode changed to: ");
    if (currentState == POLY_MODE) Serial.println("POLY_MODE");
    else if (currentState == SNAP_MODE) Serial.println("SNAP_MODE");
    else if (currentState == ARP_MODE)  Serial.println("ARP_MODE");
  }
  lastModeButtonState = newModeButtonState;
}

void checkWaveformChange() {
  bool newWaveButtonState = digitalRead(waveChangeButtonPin);
  if (newWaveButtonState == HIGH && lastWaveButtonState == LOW) {
    delay(DEBOUNCE_DELAY);
    currentWaveformIndex = (currentWaveformIndex + 1) % numWaveforms;
    // Update waveform for all oscillators.
    changeWaveform(waveformTypes[currentWaveformIndex]);
    Serial.print("Waveform changed to index: ");
    Serial.println(currentWaveformIndex);
  }
  lastWaveButtonState = newWaveButtonState;
}

void updateEffect() {
  bool newEffectButtonState = digitalRead(effectButtonPin);
  if (newEffectButtonState == HIGH && lastEffectButtonState == LOW) {
    delay(DEBOUNCE_DELAY);
    effectEnabled = !effectEnabled;
    if (effectEnabled) {
      // Enable delay effect: 100ms delay, 50% feedback, 50% mix.
      delayEffect.delay(0,100);
      Serial.println("Effect enabled.");
    } else {
      // Disable effect by setting parameters to zero.
      delayEffect.delay(0,0);
      Serial.println("Effect disabled.");
    }
  }
  lastEffectButtonState = newEffectButtonState;
}

// --- Mode Entry Functions ---
void enterPolyMode() {
  clearAllNotes();
  activatePolyphonicMode();
}

void enterSnapMode() {
  clearAllNotes();
  activateSnapBackMode();
}

void enterArpMode() {
  clearAllNotes();
  activateArpeggiatorMode();
}

// --- Mode Update Functions ---
void updatePolyMode() {
  // In Poly Mode, MIDI events drive note allocation.
  BigMasterMixer.gain(0, 1.0);
  BigMasterMixer.gain(1, 0.0);
}

void updateSnapMode() {
  // Add periodic tasks for Snap-Back mode if needed.
}

void updateArpMode() {
  // Call the arpeggiator update.
  BigMasterMixer.gain(0, 1.0);
  BigMasterMixer.gain(1, 0.0);
  updateArpeggiator();
}

// --- Mode Activation Functions ---
void activatePolyphonicMode() {
  BigMasterMixer.gain(0, 1.0);
  BigMasterMixer.gain(1, 0.0);
  
  const float oscAmp = 0.8;
  for (byte i = 0; i < MAX_WAVEFORMS; i++) {
    polyWaves[i].begin(waveformTypes[currentWaveformIndex]);
    polyWaves[i].amplitude(oscAmp);
    polyWaves[i].phase(0);
    polyEnvs[i].noteOff();
  }
  
  const float individualGain = 0.2f;
  for (byte i = 0; i < 4; i++) {
    polyMix1.gain(i, individualGain);
    polyMix2.gain(i, individualGain);
  }
  
  Serial.println("Poly mode activated.");
}

void activateSnapBackMode() {
  BigMasterMixer.gain(0, 0.0);
  BigMasterMixer.gain(1, 1.0);
  snapBackMix.gain(0, 1);
  snapBackMix.gain(1, 1);
  snapBackMix.gain(2, 1);
  
  snapBackWave.begin(waveformTypes[currentWaveformIndex]);
  snapBackWaveStack.begin(waveformTypes[currentWaveformIndex]);
  snapBackWave.pulseWidth(0.15);
  snapBackWaveStack.pulseWidth(0.15);
  snapBackEnv.delay(0.0);
  snapBackEnv.hold(0.0);
  
  Serial.println("Snap-back mode activated.");
}

void activateArpeggiatorMode() {
  BigMasterMixer.gain(0, 1.0);
  BigMasterMixer.gain(0, 0.0);
  for (byte i = 0; i < MAX_WAVEFORMS; i++) {
    polyEnvs[i].noteOff();
    polyWaves[i].amplitude(0);
  }
  polyWaves[0].begin(waveformTypes[currentWaveformIndex]);
  polyWaves[0].amplitude(0.75);
  polyWaves[0].phase(0);
  
  arpCount = 0;
  currentArpIndex = 0;
  lastArpTime = millis();
  cycleStartTime = millis();
  previousStep = 255;
  frozenArpCount = 0;
  
  Serial.println("Arpeggiator mode activated.");
}

// --- Audio Setup Functions ---
void setUpAudio() {
  AudioMemory(30);
  audioShield.enable();
  audioShield.volume(0.32);
  audioShield.lineOutLevel(13);
  audioShield.adcHighPassFilterDisable();
  audioShield.enhanceBassEnable();
}

void setUpUSBMidi() {
  myusb.begin();
  midi1.setHandleNoteOn(myNoteOn);
  midi1.setHandleNoteOff(myNoteOff);
}

void initLFO() {
  LFO.begin(WAVEFORM_TRIANGLE);
}

void USBTaskRead() {
  myusb.Task();
  midi1.read();
}

// --- Common Functions ---
void changeWaveform(int waveformType) {
  // Update all oscillator objects to use the new global waveform.
  for (byte i = 0; i < MAX_WAVEFORMS; i++) {
    polyWaves[i].begin(waveformType);
  }
  snapBackWave.begin(waveformType);
  snapBackWaveStack.begin(waveformType);
}

void clearAllNotes() {
  for (byte i = 0; i < MAX_POLYPHONY; i++) {
    polyEnvs[i].noteOff();
    polyWaves[i].amplitude(0);
    activeNotes[i] = 0;
  }
  snapBackEnv.noteOff();
  
  keyBufferSize = 0;
  for (byte i = 0; i < BUFFER_SIZE; i++) {
    keyBuffer[i] = 255;
  }
  
  arpCount = 0;
  currentArpIndex = 0;
  lastArpTime = millis();
  cycleStartTime = millis();
  previousStep = 255;
  frozenArpCount = 0;
}

// --- MIDI Handler Functions ---
void addArpNote(byte note) {
  for (byte i = 0; i < arpCount; i++) {
    if (arpNotes[i] == note) return;
  }
  if (arpCount < BUFFER_SIZE) {
    arpNotes[arpCount++] = note;
  }
}

void removeArpNote(byte note) {
  for (byte i = 0; i < arpCount; i++) {
    if (arpNotes[i] == note) {
      for (byte j = i; j < arpCount - 1; j++) {
        arpNotes[j] = arpNotes[j + 1];
      }
      arpCount--;
      if (currentArpIndex >= arpCount && arpCount > 0) {
        currentArpIndex = 0;
      }
      return;
    }
  }
}

void myNoteOn(byte channel, byte note, byte velocity) {
  if (!isValidMidiNote(note)) return;
  globalNote = note;
  globalVelocity = velocity;
  
  if (currentState == SNAP_MODE) {
    keyBuff(note, true);
  } else if (currentState == ARP_MODE) {
    addArpNote(note);
    keyState[note] = true;
  } else {
    playPolyNote(note);
    keyState[note] = true;
  }
}

void myNoteOff(byte channel, byte note, byte velocity) {
  if (!isValidMidiNote(note)) return;
  
  if (currentState == SNAP_MODE) {
    keyBuff(note, false);
  } else if (currentState == ARP_MODE) {
    removeArpNote(note);
    keyState[note] = false;
  } else {
    stopPolyNote(note);
    keyState[note] = false;
  }
}

void keyBuff(byte note, bool noteOn) {
  if (noteOn && keyBufferSize < BUFFER_SIZE) {
    oscPlay(note);
    keyBuffer[keyBufferSize++] = note;
    return;
  } else if (!noteOn && keyBufferSize > 0) {
    for (byte i = 0; i < keyBufferSize; i++) {
      if (keyBuffer[i] == note) {
        for (byte j = i; j < keyBufferSize - 1; j++) {
          keyBuffer[j] = keyBuffer[j + 1];
        }
        keyBufferSize--;
        keyBuffer[keyBufferSize] = 255;
        if (keyBufferSize > 0)
          oscPlay(keyBuffer[keyBufferSize - 1]);
        else
          oscStop();
        break;
      }
    }
  }
}

void playPolyNote(byte note) {
  byte voiceIndex = 255;
  byte startIndex = roundRobinIndex;
  
  if (activeNotes[startIndex] == 0) {
    voiceIndex = startIndex;
  } else {
    for (byte i = 1; i < MAX_POLYPHONY; i++) {
      byte idx = (startIndex + i) % MAX_POLYPHONY;
      if (activeNotes[idx] == 0) {
        voiceIndex = idx;
        break;
      }
    }
  }
  
  if (voiceIndex == 255) {
    Serial.println("No available voices for new note");
    return;
  }
  
  activeNotes[voiceIndex] = note;
  roundRobinIndex = (voiceIndex + 1) % MAX_POLYPHONY;
  
  byte waveIndex = voiceIndex % MAX_WAVEFORMS;
  float baseFreq = noteFreqs[note];
  float newFreq = baseFreq * detuneFactors[voiceIndex];
  
  polyWaves[waveIndex].frequency(newFreq);
  polyWaves[waveIndex].phase(0.0);
  polyEnvs[waveIndex].noteOn();
}

void stopPolyNote(byte note) {
  for (byte i = 0; i < MAX_POLYPHONY; i++) {
    if (activeNotes[i] == note) {
      activeNotes[i] = 0;
      byte waveIndex = i % MAX_WAVEFORMS;
      polyEnvs[waveIndex].noteOff();
      Serial.print("Stopping note: ");
      Serial.println(note);
      break;
    }
  }
}

void oscPlay(byte note) {
  snapBackWave.frequency(noteFreqs[note]);
  snapBackWaveStack.frequency(noteFreqs[note + OCTAVE_SHIFT]);
  float velo = globalVelocity * DIV127;
  snapBackWave.amplitude(velo);
  snapBackWaveStack.amplitude(velo);
  snapBackEnv.noteOn();
}

void oscStop() {
  snapBackEnv.noteOff();
}

// --- Arpeggiator Update Function ---
void updateArpeggiator() {
  uint16_t lfoVal = analogRead(potLFOSpeed);
  unsigned long period = map(lfoVal, 0, 1023, 200UL, 1000UL);
  unsigned long now = millis();

  if (now - cycleStartTime >= period) {
    cycleStartTime = now;
    previousStep = 255;
    frozenArpCount = arpCount;
    if (frozenArpCount > 0) {
      memcpy(frozenArpNotes, arpNotes, frozenArpCount);
    }
  }

  if (frozenArpCount == 0) {
    polyEnvs[0].noteOff();
    return;
  }

  unsigned long stepInterval = period / frozenArpCount;
  byte currentStep = (now - cycleStartTime) / stepInterval;

  if (currentStep != previousStep) {
    previousStep = currentStep;
    byte note = (currentStep == 0) ? frozenArpNotes[0] : frozenArpNotes[currentStep];
    polyWaves[0].frequency(noteFreqs[note]);
    polyEnvs[0].noteOff();
    polyEnvs[0].noteOn();
  }
}

// --- LFO and ADSR Updates ---
void LFOUpdate() {
  LFOspeed = map(analogRead(potLFOSpeed), 0, 1023, 1, 200) / 10.0f;
  LFOdepth = analogRead(potLFODepth) / 1023.0f;
  LFO.frequency(LFOspeed);
  LFO.amplitude(LFOdepth);
}

void ADSRUpdate() {
  int rawAttack  = analogRead(potAttack);
  int rawDecay   = analogRead(potDecay);
  int rawRelease = analogRead(potRelease);
  int attack  = (rawAttack / 1023.0f) * 3000;
  int decay   = (rawDecay  / 1023.0f) * 3000;
  float sustain = analogRead(potSustain) / 1023.0f;
  int release = (rawRelease / 1023.0f) * 3000;
  
  if (attack  < 20) attack  = 0;
  if (decay   < 20) decay   = 0;
  if (release < 20) release = 0;
  
  #ifdef DEBUG_ADSR
    Serial.print("ADSR Update: ");
    Serial.print("rawAttack = "); Serial.print(rawAttack);
    Serial.print(" -> attack = "); Serial.print(attack);
    Serial.print(" | rawDecay = "); Serial.print(rawDecay);
    Serial.print(" -> decay = "); Serial.print(decay);
    Serial.print(" | rawSustain = "); Serial.print(analogRead(potSustain));
    Serial.print(" -> sustain = "); Serial.print(sustain, 3);
    Serial.print(" | rawRelease = "); Serial.print(rawRelease);
    Serial.print(" -> release = "); Serial.println(release);
  #endif
  
  if (currentState == SNAP_MODE) {
    snapBackEnv.attack(attack);
    snapBackEnv.decay(decay);
    snapBackEnv.sustain(sustain);
    snapBackEnv.release(release);
  } else {
    for (byte i = 0; i < MAX_POLYPHONY; i++) {
      polyEnvs[i].attack(attack);
      polyEnvs[i].decay(decay);
      polyEnvs[i].sustain(sustain);
      polyEnvs[i].release(release);
    }
  }
}
