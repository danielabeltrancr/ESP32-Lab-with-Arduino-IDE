#ifndef LIGHTS_CONTROL_FISH_H
#define LIGHTS_CONTROL_FISH_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Config.h"

class LightsFishTank {
  public:
    LightsFishTank();
    LightsFishTank(int _pixels2, int _pinLED2);
    void initLights();
    void Lights_On();

  private:
    int pixels2;
    int pinLED2;
    Adafruit_NeoPixel moduleFish; 
};

#endif
