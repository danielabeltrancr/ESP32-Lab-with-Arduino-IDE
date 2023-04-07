#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H
#include <Arduino.h>
#include "Config.h"

class LightSensor {
  public:
    LightSensor();
    LightSensor(String tagLS, int pinLS);
    String getLSName();
    int captureLightValue();
    
  private:
    int pinLS;
    String tagLS;
    int luminosity = 0;
    int valLuminosity;
    unsigned long timerDelay = 0; 
    long interval = 5000; // 1000 = 1.008 seconds
};

#endif
