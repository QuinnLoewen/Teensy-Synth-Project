# 🎛️ Teensy Synth Project - I/O & Wiring Guide

This document details the **input/output connections** and how to wire each component to the **Teensy 4.1** for the **Teensy Synth Project**.

---

## 🖥️ **Microcontroller: Teensy 4.1**

| Pin | Function | Connected To |
|------|-----------|----------------|
| GND  | Ground | Common GND for all components |
| 3.3V | Power | TFT Display, Potentiometers |
| 5V   | Power | PCM5102A DAC (if using 5V version) |
| 9    | TFT RST | ST7735 Reset Pin |
| 8    | TFT DC  | ST7735 DC Pin |
| 10   | TFT CS  | ST7735 Chip Select (CS) |
| 11   | SPI MOSI | TFT Display, PCM5102A (Data) |
| 13   | SPI SCK  | TFT Display, PCM5102A (Clock) |
| A17  | Attack Potentiometer | ADSR Attack Control |
| A16  | Decay Potentiometer | ADSR Decay Control |
| A15  | Sustain Potentiometer | ADSR Sustain Control |
| A14  | Release Potentiometer | ADSR Release Control |
| A10  | LFO Rate Potentiometer |  LFO Rate Control |
| A11  | LFO Depth Potentiometer | LFO Depth  Control |
| 33   | Mode Button | Toggle Poly/Mono/Arp modes |
| 35   | Waveform Button | Cycle through waveforms |
| 36   | Effects Button | Cycle through and enable effects|
| See Pinout | MIDI Input | USB Host  |


---

## 📟 **TFT Display (ST7735 - SPI Connection)**

| TFT Pin | Teensy Pin |
|---------|------------|
| VCC | 3.3V |
| GND | GND |
| CS | 37 |
| RESET | 30 |
| DC | 29 |
| MOSI | 26 |
| SCK | 27 |

---

## 🎚️ **Potentiometer Wiring (ADSR Controls)**
Each **10K potentiometer** has 3 pins:
- **Left Pin → GND**
- **Middle Pin → Analog Input (A14 - A17)**
- **Right Pin → 3.3V**

| Potentiometer | Connected To |
|--------------|-------------|
| Attack | A17 |
| Decay | A16 |
| Sustain | A15 |
| Release | A14 |

---

## 🎵 **MIDI Connections (USB & Serial MIDI)**
### **1️⃣ USB MIDI (Preferred Method)**
- **Teensy 4.1 supports USB MIDI natively**.
- Connect your USB MIDI keyboard directly to the **Teensy USB Host Port**.
- In software, use `USBHost_t36` library to read MIDI data.

## 🎼 **Audio Output (PCM5102A DAC - I2S)**
The **PCM5102A DAC** connects using **I2S protocol**.

| DAC Pin | Teensy Pin |
|---------|------------|
| VCC | 5V (or 3.3V for low-power version) |
| GND | GND |
| BCK (Bit Clock) | 21 |
| LCK (Word Clock) | 23 |
| DIN (Data In) | 7 |

---

## 🔘 **Buttons (Mode & Waveform Selection)**
Each **push button** has 2 pins:
- **One pin → GND**
- **Other pin → Teensy Digital Input (37 for Mode, 36 for Waveform)**
- Use `INPUT_PULLUP` in the code to enable internal pull-up resistors.

---

## 📜 **Wiring Diagram (Visual Representation)**
For a graphical representation, check the `Hardware/schematics/` folder for:
- **Teensy Synth Pinout Diagram** (`teensy_synth_pinout.png`)
- **Full Wiring Schematic** (`teensy_synth_circuit.png`)

---

## ✅ **Final Checklist**
Before powering up, verify:
- All **GND connections** are linked.
- **3.3V components** (TFT, potentiometers) are not connected to 5V.
- **SPI/I2C/MIDI wiring** follows the tables above.
- **DAC & MIDI circuits** are correctly grounded.


---

This guide ensures correct I/O wiring for the **Teensy Synth Project**.
