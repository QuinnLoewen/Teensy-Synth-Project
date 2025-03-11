#ifndef ARPEGGIATOR_H
#define ARPEGGIATOR_H

#include "constants.h"
#include "globals.h"
#include "audio_setup.h"

// Use inline functions to allow inclusion in multiple translation units
inline void addArpNote(byte note) {
  for (byte i = 0; i < arpCount; i++) {
    if (arpNotes[i] == note) return;
  }
  if (arpCount < BUFFER_SIZE) {
    arpNotes[arpCount++] = note;
  }
}

inline void removeArpNote(byte note) {
  for (byte i = 0; i < arpCount; i++) {
    if (arpNotes[i] == note) {
      for (byte j = i; j < arpCount - 1; j++) {
        arpNotes[j] = arpNotes[j + 1];
      }
      arpCount--;
      return;
    }
  }
}

inline void updateArpeggiator() {
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
    byte note = frozenArpNotes[currentStep % frozenArpCount];
    polyWaves[0].frequency(noteFreqs[note]);
    polyEnvs[0].noteOff();
    polyEnvs[0].noteOn();
  }
}

#endif
