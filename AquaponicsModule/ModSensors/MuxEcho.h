#ifndef MUX_ECHO_H
#define MUX_ECHO_H
#include <Arduino.h>
#include <CD74HC4067.h>
#include "Config.h"

class Mux_Echo {
  public:
    Mux_Echo();
    Mux_Echo(String _tagHeight, int _pinS0, int _pinS1, int _pinS2, int _pinS3, int _pinSIG);  
    String getUltrasonicName();                         
    String captureHeights();
    
  private:
    int pinSIG;
    long Time, Distance, Height;
    long heights[16];
    String tagHeight;
    String heightsString = "";
    CD74HC4067 mux_control;
};

#endif
