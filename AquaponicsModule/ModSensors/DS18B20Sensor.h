#ifndef SENSOR_DS18B20_H
#define SENSOR_DS18B20_H
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Config.h"

class DS18B20Sensor {
  public:
    DS18B20Sensor();
    DS18B20Sensor(String tagTS);
    String getTSName();
    float captureWaterTemperature();

  private:
    String tagTS;
    float waterTemp;
    unsigned long timerDelay = 0; 
    long interval = 5000; // 1000 = 1.008 seconds
    static OneWire* _oneWire;
    static DallasTemperature* _sensor;
};

#endif
