# 🎵 Teensy Synth Project - Standalone Version (Without Analog Filtering)

This guide covers the setup and operation of the **Teensy Synth Standalone Version**, which outputs **digital audio** directly from the PCM5102A DAC **without external analog filtering or a custom power supply**.

---

## 📦 **What's Included**
- **Teensy 4.1** microcontroller
- **PCM5102A DAC** (I2S audio output)
- **ST7735 TFT Display** (for waveform and parameter visualization)
- **6x Potentiometers** (ADSR control & LFO control)
- **Mode, Waveform and Effect buttons** (switch between modes, sound types and effects)
- **USB MIDI support** (connect to a MIDI keyboard)

---

## 🔌 **Hardware Setup**
### **1️⃣ Powering the Synth**
- Power the **Teensy 4.1** via **USB** (connected to a computer or USB power adapter).
- No additional power regulation is required.

### **2️⃣ Connecting MIDI**
- **USB MIDI:** Connect a MIDI keyboard to the **Teensy USB Host port**.
- **5-Pin MIDI (Optional):** If using a traditional MIDI controller, connect the **MIDI OUT** from your keyboard to the **MIDI IN** of the synth.

### **3️⃣ Audio Output**
- Connect the **3.5mm or RCA line-out** from the **PCM5102A DAC** to a **powered speaker, audio interface, or headphones**.
- This version does **not** use external filtering; audio quality depends on the DAC’s built-in processing.
- reroute the audio connection in `audio_setup.h` to setup standalone version

---

## 🎚️ **Controls & Functions**
### **🎛️ Knob Controls (ADSR & LFO)**
| Knob | Function |
|------|----------|
| **Attack** | Adjusts the time for the note to reach full volume. |
| **Decay** | Controls how quickly the volume decreases after attack. |
| **Sustain** | Sets the volume level during the sustain phase. |
| **Release** | Determines how long the sound fades out after release. |
| **LFO Rate** | Determines the frequency of the LFO. |
| **LFO Depth** | Determines the amplitude of the LFO. |


### **🔘 Button Controls**
| Button | Function |
|--------|----------|
| **Mode Button** | Toggle between Polyphonic, Snap-back, and Arpeggiator modes. |
| **Waveform Button** | Cycle through waveforms (Sine, Square, Triangle, Sawtooth). |
| **Effect Button** | Cycle through effects (just delay right now). |



---

## 🎼 **Using the Synth**
### **1️⃣ Selecting a Mode**
- **Polyphonic Mode:** Multiple notes can be played at once.
- **Snap-back Mode:** Monophonic mode where the last played note takes over.
- **Arpeggiator Mode:** Cycles through held notes in an arpeggiated sequence.

### **2️⃣ Sound Customization**
- Adjust **ADSR envelope settings** for shaping notes.
- Modify **LFO settings** for modulation effects.
- Switch **waveforms** to explore different tonal characteristics.

---

## 🔧 **Customization & Advanced Settings**
### **📟 Adjusting Display Settings**
- The **ST7735 TFT screen** provides live feedback for waveform type, ADSR settings, and LFO modulation.
- Display update rate can be modified in `display.cpp`.

### **🎹 MIDI Configuration**
- The synth listens on **MIDI channel 1** by default.
- Change the MIDI channel in `midi_handler.cpp` if needed.
- Future updates may include **MIDI CC mapping** for external parameter control.

### **🎛️ Expanding Sound Capabilities**
- Users can modify the Teensy Audio Library **to add filtering, reverb, and delay**.
- Adjust `AudioEffect*` objects in `synth_engine.cpp` for custom effects.

---

## 🚨 **Troubleshooting**
| Issue | Solution |
|-------|----------|
| No sound output | Check DAC wiring and volume settings. |
| MIDI keyboard not detected | Ensure USB connection is secure; try another cable. |
| Display not updating | Verify SPI wiring for the TFT display. |
| Notes stuck on | Check **Note Off** handling in `midi_handler.cpp`. |

---

## 🛠️ **Firmware Updates**
1. Connect **Teensy 4.1** via USB.
2. Open **Arduino IDE or PlatformIO**.
3. Open `TeensySynth.ino`, set board type to `Teensy 4.1`.
4. Click **Upload** to flash new firmware.

---

## 📜 **Additional Resources**
- **Schematics & wiring diagrams:** `Hardware/schematics/`
- **Code documentation:** `Software/src/`
- **MIDI implementation details:** `Documentation/MIDI_Implementation.md`
