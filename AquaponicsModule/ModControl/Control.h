#ifndef CONTROL_H
#define CONTROL_H
#include <Arduino.h>
#include "EspNow.h"
#include "Lights_Plants.h"

LightsPlants objLightsPlants(pixels1, pinLED1);

int incomingLightValue;
unsigned long timerDelay = 0;
long interval = 60000;     //1000 = 1.008 s

void Control() {
  incomingLightValue = Data.sensorValue_1;
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= interval) {
    timerDelay = timepoint;
    if (incomingLightValue > 90) {
      objLightsPlants.Default_Lights();
    }else{
      objLightsPlants.Lights_Off();   
    }
  }
}

#endif
