#ifndef MUX_ECHO_H
#define MUX_ECHO_H
#include <Arduino.h>
#include <CD74HC4067.h>

class Mux_Echo {
  public:
    //Mux_Echo();
    Mux_Echo(int _pinS0, int _pinS1, int _pinS2, int _pinS3, int _pinSIG);                         
    String getHeights();
    
  private:
    int pinSIG;
    String heightsString = "";
    long d, t;
    long heights[16];
    CD74HC4067 mux_control;
};

#endif
