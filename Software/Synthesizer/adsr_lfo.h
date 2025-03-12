#ifndef ADSR_LFO_H
#define ADSR_LFO_H

#include "constants.h"
#include "globals.h"
#include "audio_setup.h"
#include "ui_display.h"

// Ensure that the following pin constants (potAttack, potDecay, etc.) are defined in your constants.h file.

inline void ADSRUpdate() {
  int rawAttack  = analogRead(potAttack);
  int rawDecay   = analogRead(potDecay);
  int rawSustain = analogRead(potSustain);
  int rawRelease = analogRead(potRelease);

  int attack  = (rawAttack  * 3000) / 1023;
  int decay   = (rawDecay   * 3000) / 1023;
  float sustain = rawSustain / 1023.0f;
  int releaseVal = (rawRelease * 3000) / 1023;


  // Update global display variables
  gAttack = attack;
  gDecay = decay;
  gSustain = sustain;
  gRelease = releaseVal;

  Serial.print("ADSR Update: ");
  Serial.print("rawAttack = "); Serial.print(rawAttack);
  Serial.print(" -> attack = "); Serial.print(attack);
  Serial.print(" | rawDecay = "); Serial.print(rawDecay);
  Serial.print(" -> decay = "); Serial.print(decay);
  Serial.print(" | rawSustain = "); Serial.print(rawSustain);
  Serial.print(" -> sustain = "); Serial.print(sustain, 3);
  Serial.print(" | rawRelease = "); Serial.print(rawRelease);
  Serial.print(" -> release = "); Serial.println(releaseVal);

  if (currentState == SNAP_MODE) {
    snapBackEnv.attack(attack);
    snapBackEnv.decay(decay);
    snapBackEnv.sustain(sustain);
    snapBackEnv.release(releaseVal);
  } else {
    for (byte i = 0; i < MAX_POLYPHONY; i++) {
      polyEnvs[i].attack(attack);
      polyEnvs[i].decay(decay);
      polyEnvs[i].sustain(sustain);
      polyEnvs[i].release(releaseVal);
    }
  }
}

inline void LFOUpdate() {
  float LFOspeed = map(analogRead(potLFOSpeed), 0, 1023, 1, 200) / 10.0f;
  float LFOdepth = analogRead(potLFODepth) / 1023.0f;
  LFO.frequency(LFOspeed);
  LFO.amplitude(LFOdepth);

  // Store for display
  gLFOSpeed = LFOspeed;
  gLFOdepth = LFOdepth;
}

void initLFO() {
  LFO.begin(WAVEFORM_TRIANGLE);
}


#endif
