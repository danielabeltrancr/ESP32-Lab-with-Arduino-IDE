#include "MuxEcho.h"

Mux_Echo::Mux_Echo(String _tagHeight, int _pinS0, int _pinS1, int _pinS2, int _pinS3, int _pinSIG) : mux_control(_pinS0, _pinS1, _pinS2, _pinS3) {
  tagHeight = _tagHeight;
  pinSIG = _pinSIG;
  pinMode(_pinS0, OUTPUT);
  pinMode(_pinS1, OUTPUT);
  pinMode(_pinS2, OUTPUT);
  pinMode(_pinS3, OUTPUT);
  pinMode(_pinSIG, INPUT);
}

String Mux_Echo::getUltrasonicName() {
  return tagHeight;
}

String Mux_Echo::captureHeights() {
  heightsString = "";
  for (int i = 0; i < 16; i++) {
    mux_control.channel(i);
    Time = pulseIn(pinSIG, HIGH);
    Distance = Time/59;
    Height = 40 - Distance;
    heights[i] = Height;
  }
  for (int Channel = 0; Channel < 16; Channel++) {
    if (Channel < 15) {
      heightsString += heights[Channel]; //convertir a string el array de las alturas
      heightsString += ",";
    } else {
      heightsString += heights[Channel];
    }
  }
  return heightsString;
}
