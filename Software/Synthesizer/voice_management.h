#ifndef VOICE_MANAGEMENT_H
#define VOICE_MANAGEMENT_H

#include "constants.h"
#include "globals.h"


inline void playPolyNote(byte note) {
  byte voiceIndex = roundRobinIndex;
  // Find a free voice
  for (byte i = 0; i < MAX_POLYPHONY; i++) {
    if (activeNotes[voiceIndex] == 0) break;
    voiceIndex = (voiceIndex + 1) % MAX_POLYPHONY;
  }
  activeNotes[voiceIndex] = note;
  roundRobinIndex = (voiceIndex + 1) % MAX_POLYPHONY;

  float baseFreq = noteFreqs[note];
  float newFreq = baseFreq * detuneFactors[voiceIndex];

  polyWaves[voiceIndex].frequency(newFreq);
  polyWaves[voiceIndex].phase(0.0);
  polyEnvs[voiceIndex].noteOn();
}

inline void stopPolyNote(byte note) {
  for (byte i = 0; i < MAX_POLYPHONY; i++) {
    if (activeNotes[i] == note) {
      activeNotes[i] = 0;
      polyEnvs[i].noteOff();
      break;
    }
  }
}

inline void clearAllNotes() {
  for (byte i = 0; i < MAX_POLYPHONY; i++) {
    polyEnvs[i].noteOff();
    activeNotes[i] = 0;
  }
  keyBufferSize = 0;
  arpCount = 0;
}

#endif
