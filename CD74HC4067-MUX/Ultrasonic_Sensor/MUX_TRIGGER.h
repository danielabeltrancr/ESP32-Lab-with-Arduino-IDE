#ifndef MUX_TRIGGER_H
#define MUX_TRIGGER_H
#include <Arduino.h>
#include <CD74HC4067.h>

class Mux_Trigger {
  public:
    Mux_Trigger();
    Mux_Trigger(int _pinS0,int _pinS1,int _pinS2,int _pinS3, int _pinSIG);                              
    void Trigger();
    
  private:
    int pinSIG;
    CD74HC4067 mux_control;
};

#endif
