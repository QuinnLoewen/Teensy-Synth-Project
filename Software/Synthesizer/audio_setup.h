#ifndef AUDIO_SETUP_H
#define AUDIO_SETUP_H

#include <Audio.h>
#include "constants.h"
#include "globals.h"

// --- Audio Objects ---
AudioSynthWaveform polyWaves[MAX_WAVEFORMS];
AudioEffectEnvelope polyEnvs[MAX_WAVEFORMS];

AudioSynthWaveform snapBackWave, snapBackWaveStack;
AudioSynthWaveformModulated snapBackMod;
AudioEffectEnvelope snapBackEnv;

AudioSynthWaveform LFO;

AudioMixer4 polyMix1, polyMix2, snapBackMix, PolyMasterMix, BigMasterMixer;

AudioEffectDelay delayEffect;
AudioOutputI2S audioOut;
AudioControlSGTL5000 audioShield;

// --- Patch Cord Connections ---
// Polyphonic voices
AudioConnection patchCordPolyEnv0(polyWaves[0], polyEnvs[0]);
AudioConnection patchCordPolyEnv1(polyWaves[1], polyEnvs[1]);
AudioConnection patchCordPolyEnv2(polyWaves[2], polyEnvs[2]);
AudioConnection patchCordPolyEnv3(polyWaves[3], polyEnvs[3]);
AudioConnection patchCordPolyEnv4(polyWaves[4], polyEnvs[4]);
AudioConnection patchCordPolyEnv5(polyWaves[5], polyEnvs[5]);
AudioConnection patchCordPolyEnv6(polyWaves[6], polyEnvs[6]);
AudioConnection patchCordPolyEnv7(polyWaves[7], polyEnvs[7]);

// Snap-back voice
AudioConnection patchCordSnapBack1(snapBackWave, 0, snapBackMix, 0);
AudioConnection patchCordSnapBack2(snapBackWave, 0, snapBackMod, 0);
AudioConnection patchCordSnapBack3(snapBackWaveStack, 0, snapBackMix, 1);
AudioConnection patchCordSnapBack4(snapBackMod, 0, snapBackMix, 2);

// Mixing polyphonic voices
AudioConnection patchCordPolyMix1(polyEnvs[0], 0, polyMix1, 0);
AudioConnection patchCordPolyMix2(polyEnvs[1], 0, polyMix1, 1);
AudioConnection patchCordPolyMix3(polyEnvs[2], 0, polyMix1, 2);
AudioConnection patchCordPolyMix4(polyEnvs[3], 0, polyMix1, 3);
AudioConnection patchCordPolyMix5(polyEnvs[4], 0, polyMix2, 0);
AudioConnection patchCordPolyMix6(polyEnvs[5], 0, polyMix2, 1);
AudioConnection patchCordPolyMix7(polyEnvs[6], 0, polyMix2, 2);
AudioConnection patchCordPolyMix8(polyEnvs[7], 0, polyMix2, 3);

// Combining mixer outputs
AudioConnection patchCordPolyMaster1(polyMix1, 0, PolyMasterMix, 0);
AudioConnection patchCordPolyMaster2(polyMix2, 0, PolyMasterMix, 1);

// Snap-back envelope routing
AudioConnection patchCordSnapBackEnv(snapBackMix, 0, snapBackEnv, 0);

// Final mix: combine PolyMasterMix and Snap-back envelope
AudioConnection patchCordBigMaster1(snapBackEnv, 0, BigMasterMixer, 1);
AudioConnection patchCordBigMaster2(PolyMasterMix, 0, BigMasterMixer, 0);

// Delay effect: insert delay between BigMasterMixer and audioOut
AudioConnection patchCordDelay(BigMasterMixer, 0, delayEffect, 0);
AudioConnection patchCordDelayOut(delayEffect, 0, audioOut, 1);

// LFO routing: LFO output remains on audioOut channel 0.
AudioConnection patchCordAudioOut2(LFO, 0, audioOut, 0);

void setUpAudio() {
  AudioMemory(30);
  audioShield.enable();
  audioShield.volume(0.32);
  audioShield.lineOutLevel(13);
  audioShield.adcHighPassFilterDisable();
  audioShield.enhanceBassEnable();
}

#endif
