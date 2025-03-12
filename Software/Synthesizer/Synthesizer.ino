#include <Arduino.h>
#include "constants.h"
#include "globals.h"
#include "audio_setup.h"
#include "midi_handling.h"
#include "voice_management.h"
#include "modes.h"
#include "adsr_lfo.h"
#include "arpeggiator.h"
#include "ui_display.h"
#include "control_inputs.h"

// --- Global Variable Definitions (only here) ---
USBHost myusb;
USBHub hub1(myusb);
MIDIDevice midi1(myusb);

byte globalNote = 0;
byte globalVelocity = 0;
byte activeNotes[MAX_POLYPHONY] = {0};
bool keyState[128] = {false};
byte roundRobinIndex = 0;

byte keyBuffer[BUFFER_SIZE] = {0};
byte keyBufferSize = 0;

byte arpNotes[BUFFER_SIZE] = {0};
byte arpCount = 0;
byte currentArpIndex = 0;
unsigned long lastArpTime = 0;
unsigned long cycleStartTime = 0;
byte previousStep = 255;
byte frozenArpNotes[BUFFER_SIZE] = {0};
byte frozenArpCount = 0;

bool lastModeButtonState = LOW;
bool lastWaveButtonState = LOW;
bool lastEffectButtonState = LOW;
bool effectEnabled = false;

// ADSR/LFO Globals
int gAttack = 0;
int gDecay = 0;
float gSustain = 0.0f;
int gRelease = 0;
float gLFOSpeed = 0.0f;
float gLFOdepth = 0.0f;


// Waveform and mode state
int currentWaveformIndex = 3; // Default: Sawtooth
ModeState currentState = POLY_MODE;

void setup() {
  Serial.begin(115200);
  setUpAudio();
  setUpUSBMidi();
  setupDisplay();
  initLFO();
  changeWaveform(currentWaveformIndex);
  enterPolyMode();
}

void loop() {
  USBTaskRead();
  updateStateMachine();
  checkWaveformChange();
  updateEffect();
  updateArpeggiator();
  ADSRUpdate();
  LFOUpdate();
  updateDisplay();
}
