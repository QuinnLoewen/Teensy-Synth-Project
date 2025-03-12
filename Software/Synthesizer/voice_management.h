#ifndef VOICE_MANAGEMENT_H
#define VOICE_MANAGEMENT_H

#include "constants.h"
#include "globals.h"

inline void oscPlay(byte note) {
  snapBackWave.frequency(noteFreqs[note]);
  snapBackWaveStack.frequency(noteFreqs[note + OCTAVE_SHIFT]);
  float velo = globalVelocity * DIV127;
  snapBackWave.amplitude(velo);
  snapBackWaveStack.amplitude(velo);
  snapBackEnv.noteOn();
}

inline void oscStop() {
  snapBackEnv.noteOff();
}


inline void keyBuff(byte note, bool noteOn) {
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
