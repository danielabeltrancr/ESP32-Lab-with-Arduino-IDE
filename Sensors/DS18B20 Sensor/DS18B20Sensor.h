#ifndef SENSOR_DS18B20_H
#define SENSOR_DS18B20_H
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Config.h"

class SensorDS18B20 {
  public:
    SensorDS18B20();
    SensorDS18B20(String tagTS);
    String getTSName();
    float captureWaterTemperature();

  private:
    float waterTemp;
    String tagTS;
    static OneWire* _oneWire;
    static DallasTemperature* _sensor;
};

#endif