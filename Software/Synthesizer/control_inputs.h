#ifndef CONTROL_INPUTS_H
#define CONTROL_INPUTS_H

#include "audio_setup.h"
#include "constants.h"
#include "globals.h"

inline void changeWaveform(int waveformType) {
  for (byte i = 0; i < MAX_WAVEFORMS; i++) {
    polyWaves[i].begin(waveformType);
  }
  snapBackWave.begin(waveformType);
  snapBackWaveStack.begin(waveformType);
}

inline void checkWaveformChange() {
  bool newWaveButtonState = digitalRead(waveChangeButtonPin);
  if (newWaveButtonState == HIGH && lastWaveButtonState == LOW) {
    delay(DEBOUNCE_DELAY);
    currentWaveformIndex = (currentWaveformIndex + 1) % numWaveforms;
    changeWaveform(currentWaveformIndex);
  }
  lastWaveButtonState = newWaveButtonState;
}

inline void updateEffect() {
  bool newEffectButtonState = digitalRead(effectButtonPin);
  if (newEffectButtonState == HIGH && lastEffectButtonState == LOW) {
    delay(DEBOUNCE_DELAY);
    effectEnabled = !effectEnabled;
    if (effectEnabled) {
      delayEffect.delay(0, map(analogRead(potLFOSpeed), 0, 1023, 200, 1000));
    } else {
      delayEffect.delay(0, 0);
    }
  }
  lastEffectButtonState = newEffectButtonState;
}


#endif
