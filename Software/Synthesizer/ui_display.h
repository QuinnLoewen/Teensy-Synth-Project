#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "constants.h"
#include "globals.h"

// Pin definitions for the TFT display
#define TFT_CS   37
#define TFT_DC   29  
#define TFT_RST  30  
#define TFT_BL   32  // Backlight control
#define TFT_MOSI 26
#define TFT_SCLK 27

// Create a static instance for the display in this module
static Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
static unsigned long lastUpdate = 0;

// Function to initialize the TFT display
inline void setupDisplay() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  tft.fillScreen(ST77XX_BLACK);
}

// Function to update the display once per second with current ADSR & LFO values.
// Global variables (gAttack, gDecay, gSustain, gRelease, gLFOSpeed, gLFOdepth, and currentWaveformIndex)
// must be declared as extern in globals.h and defined once in your main file.
inline void updateDisplay() {
  if (millis() - lastUpdate > 1000) {
    lastUpdate = millis();
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(1);
    
    tft.setCursor(0, 0);
    tft.print("ADSR:");
    
    tft.setCursor(0, 10);
    tft.print("A: "); 
    tft.print(gAttack);
    
    tft.setCursor(0, 20);
    tft.print("D:"); 
    tft.print(gDecay);
    
    tft.setCursor(0, 30);
    tft.print("S:"); 
    tft.print(gSustain, 2);
    
    tft.setCursor(0, 40);
    tft.print("R:"); 
    tft.print(gRelease);
    
    tft.setCursor(0, 55);
    tft.print("Wave: ");
    switch(currentWaveformIndex) {
      case 0: tft.print("Sine"); break;
      case 1: tft.print("Square"); break;
      case 2: tft.print("Triangle"); break;
      case 3: tft.print("Saw"); break;
      default: tft.print("Unknown"); break;
    }
    
    tft.setCursor(0, 70);
    tft.print("LFO Spd: ");
    tft.print(gLFOSpeed, 2);
    
    tft.setCursor(0, 80);
    tft.print("LFO Dep: ");
    tft.print(gLFOdepth, 2);
  }
}

#endif
