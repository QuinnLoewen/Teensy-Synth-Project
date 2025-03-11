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

byte globalNote = 0;
byte globalVelocity = 0;
byte activeNotes[MAX_POLYPHONY] = {0};
bool keyState[128] = {false};
byte roundRobinIndex = 0;
byte arpNotes[BUFFER_SIZE] = {0};
byte arpCount = 0;
unsigned long lastArpTime = 0, cycleStartTime = 0;
byte previousStep = 255;
byte frozenArpNotes[BUFFER_SIZE] = {0};
byte frozenArpCount = 0;
bool lastModeButtonState = LOW, lastWaveButtonState = LOW, lastEffectButtonState = LOW;
float LFOdepth = 0.0f, LFOspeed = 0.0f;
int gAttack = 0, gDecay = 0, gRelease = 0;
float gSustain = 0.0f, gLFOSpeed = 0.0f, gLFOdepth = 0.0f;
int currentWaveformIndex = 3;
ModeState currentState = POLY_MODE;
USBHost myusb;
USBHub hub1(myusb);
MIDIDevice midi1(myusb);

void setup() {
  Serial.begin(115200);
  setUpAudio();
  setUpUSBMidi();
  setupDisplay();
  initLFO();
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
