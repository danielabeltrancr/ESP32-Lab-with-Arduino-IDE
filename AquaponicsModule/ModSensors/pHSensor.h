#ifndef PH_SENSOR_H
#define PH_SENSOR_H
#include <Arduino.h>
#include "Config.h"
#define Offset -4.35                  //deviation compensate
#define samplingInterval 20   
#define printInterval 800
#define ArrayLenth  40                //times of collection 

class pHSensor {
  public:
    pHSensor();
    pHSensor(String _tagPH, int _pinPH);  
    String getPHName();                         
    float capturePHValue();
    double avergearray(int* arr, int number);
    
  private:
    int pinPH;
    String tagPH;
    int pHArray[ArrayLenth];          //Store the average value of the sensor feedback
    int pHArrayIndex = 0;
    float voltage, pHValue;
};

#endif
