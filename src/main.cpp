#include <Arduino.h>

#include <Audio.h>
/*
    Simple test of the Medium Quality Sound (MQS) function of the I.MX RT1060 Processor.
    Output is to the MQSR(10) and MQSL(12) pins. Connect two 100uF capacitors one to each pin,
    postive side of cap to pin. Connect a low impedance load between the negative side of the
    caps and ground. This can be something like headphones or an amplifier input. 
*/

AudioSynthWaveform waveform;

AudioOutputMQS           audioOutput;  // T4
AudioConnection          patchCord1(waveform, 0, audioOutput, 0);
AudioConnection          patchCord2(waveform, 0, audioOutput, 1);

void setup() {
  AudioMemory(8);
  waveform.begin(WAVEFORM_SAWTOOTH);
  waveform.frequency(440);
  waveform.amplitude(0.9);
}


void loop() {
}