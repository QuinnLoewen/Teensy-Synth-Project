# 🎵 Teensy Synth Project - Advanced Version (With Analog Filtering & Power Supply)

This guide provides instructions for setting up and operating the **Teensy Synth Advanced Version**, which includes **analog filtering and a dedicated power supply** for improved audio quality.

---

## 📦 **What's Included**
- **Teensy 4.1** microcontroller
- **PCM5102A DAC** (I2S audio output)
- **ST7735 TFT Display** (for waveform and parameter visualization)
- **6x Potentiometers** (ADSR control & LFO control)
- **Mode, Waveform and Effect buttons** (switch between modes, sound types and effects)
- **USB MIDI support** (connect to a MIDI keyboard or DAW)
- **Analog Filtering Circuit** (Low-pass and high-pass filters for cleaner sound)
- **Custom Power Supply** (for noise reduction and isolation)

---

## 🔌 **Hardware Setup**
### **1️⃣ Powering the Synth**
- Use an **external regulated power supply** (e.g., **9V to 12V DC adapter**) with a **5V voltage regulator** to power the Teensy and other components.
- Ensure proper grounding between power supply and components.


### **2️⃣ Connecting MIDI**
- **USB MIDI:** Connect a MIDI keyboard to the **Teensy USB Host port**.
- **5-Pin MIDI (Optional):** If using a traditional MIDI controller, connect the **MIDI OUT** from your keyboard to the **MIDI IN** of the synth.

### **3️⃣ Audio Output (Filtered Signal)**
- The output of the **PCM5102A DAC** passes through an **analog low-pass filter (LPF)** to remove unwanted digital artifacts.
- A **high-pass filter (HPF)** can be added for shaping the final sound.
- Connect the **filtered audio output** to a **mixer, amplifier, or active speakers**.
- LFO connects through the left channel output in `audio_setup.h`
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
- Utilize the **analog filters** to remove high-frequency noise or emphasize bass frequencies.

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
- The analog filter circuit can be modified to alter the sound shaping.

---

## 🚨 **Troubleshooting**
| Issue | Solution |
|-------|----------|
| No sound output | Check DAC wiring and volume settings. |
| MIDI keyboard not detected | Ensure USB connection is secure; try another cable. |
| Display not updating | Verify SPI wiring for the TFT display. |
| Notes stuck on | Check **Note Off** handling in `midi_handler.cpp`. |
| Noise or distortion | Ensure proper power supply filtering and grounding. |

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
- **Analog Filter Circuit Design:** `Hardware/analog_filtering_schematic.pdf`

