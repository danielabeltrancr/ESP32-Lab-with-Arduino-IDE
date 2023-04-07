#ifndef LIGHTS_CONTROL_PLANTS_H
#define LIGHTS_CONTROL_PLANTS_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Config.h"

class LightsPlants {
  public:
    LightsPlants();
    LightsPlants(int _pixels1, int _pinLED1);
    void initLights();
    void Default_Lights();  
    void Lights_Off();     

  private:
    int pixels1;
    int pinLED1;
    Adafruit_NeoPixel modulePlants; 
};

#endif
