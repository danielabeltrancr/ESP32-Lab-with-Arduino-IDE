#ifndef LIGHT_SENSOR_h
#define LIGHT_SENSOR_h
#include <Arduino.h>

class LightSensor {
  public:
    LightSensor();
    LightSensor(String tagLS, int pinLS);
    String getLSName();
    int captureLightValue();
    
  private:
    int pinLS;
    String tagLS;
    unsigned long timerDelay = 1000; //1000 = 1.028 seconds
    int valLuminosity;
};

#endif