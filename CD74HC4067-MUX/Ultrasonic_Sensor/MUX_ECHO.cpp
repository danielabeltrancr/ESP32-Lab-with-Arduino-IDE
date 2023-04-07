#include "MUX_ECHO.h"
 
Mux_Echo::Mux_Echo(int _pinS0, int _pinS1, int _pinS2, int _pinS3, int _pinSIG) : mux_control(_pinS0, _pinS1, _pinS2, _pinS3) {
  pinSIG = _pinSIG;
  pinMode(_pinS0, OUTPUT);
  pinMode(_pinS1, OUTPUT);
  pinMode(_pinS2, OUTPUT);
  pinMode(_pinS3, OUTPUT);
  pinMode(_pinSIG, INPUT);
}

String Mux_Echo::getHeights() {
  for (int i = 0; i < 16; i++) {
    mux_control.channel(i);
    t = pulseIn(pinSIG, HIGH);
    d = t/59;
    heights[i] = d;
  }
  for (int Channel = 0; Channel < 16; Channel++) {
    if (Channel < 15) {
      heightsString += heights[Channel]; //convert the array of heights to string
      heightsString += ",";
    } else {
      heightsString += heights[Channel];
    }
  }
  return heightsString;
  heightsString = "";
}
