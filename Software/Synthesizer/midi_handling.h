#ifndef MIDI_HANDLING_H
#define MIDI_HANDLING_H

#include <USBHost_t36.h>
#include "constants.h"
#include "globals.h"
#include "voice_management.h"
#include "modes.h"
#include "arpeggiator.h"

// The USB objects are declared as extern in globals.h

// Inline functions to avoid multiple-definition errors:
inline void myNoteOn(byte channel, byte note, byte velocity) {
  if (!isValidMidiNote(note)) return;
  globalNote = note;
  globalVelocity = velocity;
  
  switch (currentState) {
    case SNAP_MODE:
      keyBuff(note, true);
      break;
      
    case ARP_MODE:
      addArpNote(note);
      keyState[note] = true;
      break;
      
    default:
      playPolyNote(note);
      keyState[note] = true;
      break;
  }
}

inline void myNoteOff(byte channel, byte note, byte velocity) {
  if (!isValidMidiNote(note)) return;
  
  switch (currentState) {
    case SNAP_MODE:
      keyBuff(note, false);
      break;
      
    case ARP_MODE:
      removeArpNote(note);
      keyState[note] = false;
      break;
      
    default:
      stopPolyNote(note);
      keyState[note] = false;
      break;
  }
}

inline void setUpUSBMidi() {
  myusb.begin();
  midi1.setHandleNoteOn(myNoteOn);
  midi1.setHandleNoteOff(myNoteOff);
}

inline void USBTaskRead() {
  myusb.Task();
  midi1.read();
}

#endif
