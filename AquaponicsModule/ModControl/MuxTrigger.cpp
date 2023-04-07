#include "MuxTrigger.h"

Mux_Trigger::Mux_Trigger(int _pinS0, int _pinS1, int _pinS2, int _pinS3, int _pinSIG) : mux_control(_pinS0, _pinS1, _pinS2, _pinS3) {
  pinSIG = _pinSIG;
  pinMode(_pinS0, OUTPUT);
  pinMode(_pinS1, OUTPUT);
  pinMode(_pinS2, OUTPUT);
  pinMode(_pinS3, OUTPUT);
  pinMode(_pinSIG, OUTPUT);
}

void Mux_Trigger::Trigger(){
  for (int i = 0; i < 16; i++) {
    mux_control.channel(i);
    digitalWrite(pinSIG, LOW);
    delayMicroseconds(4);
    digitalWrite(pinSIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinSIG, LOW);
  }
}
