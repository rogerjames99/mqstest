#include <Arduino.h>

#include <Audio.h>
/*
    Simple test of the Medium Quality Sound (MQS) function of the I.MX RT1060 Processor.
    Output is to the MQSR(10) and MQSL(12) pins. Connect two 100uF capacitors one to each pin,
    postive side of cap to pin. Connect a low impedance load between the negative side of the
    caps and ground. This can be something like headphones or an amplifier input. 
*/

#ifdef WAVEFORM
AudioSynthWaveform input;
#else
AudioSynthToneSweep input;
#endif

AudioOutputMQS           audioOutput;  // T4
AudioConnection          patchCord1(input, 0, audioOutput, 0);
AudioConnection          patchCord2(input, 0, audioOutput, 1);

void setup() {
  AudioMemory(8);
#ifdef WAVEFORM
  input.begin(WAVEFORM_SAWTOOTH);
  input.frequency(440);
  input.amplitude(0.9);
#else
while(true)
{
  input.play(0.9, 30, 3000, 10);
  while(input.isPlaying());
  input.play(0.9, 3000, 30, 10);
  while(input.isPlaying());
}
#endif
}


void loop() {
}