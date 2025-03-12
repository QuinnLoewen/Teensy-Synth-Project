# 🎵 Teensy Synth Project - Contributors & Responsibilities

This document outlines the team members and their contributions to the **Teensy Synth Project**, detailing responsibilities across hardware, software, testing, and documentation.

---

## 👨‍💻 **Project Lead & System Architect**
**[Quinn Loewen]**  
- **Project Vision & Design**: Defined the synthesizer’s features and architecture.
- **Hardware Selection**: Chose Teensy 4.1, PCM5102A DAC, ST7735 LCD, and potentiometers.
- **Software Development**:
  - Designed core **synthesis engine** (polyphony, waveform handling, ADSR, LFOs).
  - Integrated **MIDI handling & USB Host support**.
  - Implemented **mode switching** (Polyphonic, Snap-back, Arpeggiator).
- **Final Report & Documentation**: Outlined the system architecture and signal routing.

---

## 🔧 **Hardware & Circuit Design**
**[Julius Andrews, Christian Payette, Zander Wells]**
- **Schematics & Wiring**: Created circuit diagrams for all components.
- **PCB Design (if applicable)**: Designed and tested PCB for Teensy-based synth.
- **Component Assembly & Testing**: Wired potentiometers, buttons, and display.
- **Filtering**: Implemented HP, LP and resonant filters for analog filtering.

---

## 🎹 **MIDI & Audio Processing**
**[Quinn Loewen]**
- **MIDI Integration**: Handled USB and 5-pin MIDI communication.
- **MIDI Note Processing**: Implemented dynamic voice allocation.
- **Real-time Audio Processing**:
  - Developed Teensy **Audio Library patch routing**.
  - Fine-tuned **oscillators and envelopes**.

---

## 🖥️ **Software & Firmware Development**
**[Quinn Loewen]**
- **Teensy Firmware**: Wrote core loop and function handlers.
- **Display UI Development**:
  - Coded real-time **TFT screen updates**.
  - Designed **waveform and ADSR visualization**.
- **Optimization**: Reduced CPU usage & improved latency.

---

## 📊 **Testing & Debugging**
**[Quinn Loewen]**
- **MIDI Latency Testing**: Measured MIDI-to-audio response time (~1.2 ms avg.).
- **Polyphony Stress Testing**: Ensured stable playback of 8 voices.
- **Signal Integrity**: Checked for distortion/clipping in DAC output.
- **Bug Fixing**: Debugged MIDI inconsistencies and envelope behavior.

---

## 📜 **Documentation & Reporting**
**[Quinn Loewen]**
- **README & User Guide**: Wrote setup, usage, and technical documentation.
- **Final Engineering Report**: Collected test results and system analysis.
- **Code Documentation**: Added comments and structured files.

---

## 🌟 **Acknowledgments**
- **Paul Stoffregen & PJRC** for the **Teensy 4.1 platform**.
- **Adafruit** for the **TFT Display Libraries**.
- **Mozzi & Teensy Audio Library Contributors** for synthesis tools.
- **Open-source MIDI resources** for protocol handling.
- **Jeanie Synth** for showing us the dream.

---

## 🚀 **Future Development**
- Adding **new waveforms & effects** (reverb, chorus, phaser).
- Designing a **custom PCB** for a more compact synth module.
- Refining **TFT Display** for a better visual representaiton.

---

### 📨 Contact
For project-related inquiries, reach out via GitHub Issues or [Your Email].
