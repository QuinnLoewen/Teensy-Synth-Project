#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <USBHost_t36.h>
#include "constants.h"

// USB Globals
extern USBHost myusb;
extern USBHub hub1;
extern MIDIDevice midi1;

// MIDI Globals
extern byte globalNote;
extern byte globalVelocity;
extern byte activeNotes[MAX_POLYPHONY];
extern bool keyState[128];
extern byte roundRobinIndex;

// Key Buffer and Arpeggiator
extern byte keyBuffer[BUFFER_SIZE];
extern byte keyBufferSize;

extern byte arpNotes[BUFFER_SIZE];
extern byte arpCount;
extern byte currentArpIndex;
extern unsigned long lastArpTime;
extern unsigned long cycleStartTime;
extern byte previousStep;
extern byte frozenArpNotes[BUFFER_SIZE];
extern byte frozenArpCount;

// Button States and Pins
extern const int modeButtonPin;
extern const int waveChangeButtonPin;
extern const int effectButtonPin;
extern bool lastModeButtonState;
extern bool lastWaveButtonState;
extern bool lastEffectButtonState;
extern bool effectEnabled;

// ADSR/LFO Globals
extern int gAttack;
extern int gDecay;
extern float gSustain;
extern int gRelease;
extern float gLFOSpeed;
extern float gLFOdepth;

extern float LFOspeed;
extern float LFOdepth;

// Waveform and Mode State
extern int currentWaveformIndex;
extern ModeState currentState;

#endif
