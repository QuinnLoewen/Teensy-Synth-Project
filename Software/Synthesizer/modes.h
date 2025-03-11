#ifndef MODES_H
#define MODES_H

#include "voice_management.h"
#include "audio_setup.h"
#include "constants.h"
#include "globals.h"

// Inline functions to prevent multiple definitions

inline void enterPolyMode() {
  clearAllNotes();
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

inline void enterSnapMode() {
  clearAllNotes();
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

inline void enterArpMode() {
  clearAllNotes();
  BigMasterMixer.gain(1, 0.0);
  BigMasterMixer.gain(0, 1.0);
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

inline void updateStateMachine() {
  bool newModeButtonState = digitalRead(modeButtonPin);
  if (newModeButtonState == HIGH && lastModeButtonState == LOW) {
    delay(DEBOUNCE_DELAY);
    if (currentState == POLY_MODE)
      currentState = SNAP_MODE;
    else if (currentState == SNAP_MODE)
      currentState = ARP_MODE;
    else
      currentState = POLY_MODE;

    clearAllNotes();

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

#endif
