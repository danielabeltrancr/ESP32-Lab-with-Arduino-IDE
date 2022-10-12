#include "DS18B20Sensor.h"

SensorDS18B20::SensorDS18B20() {}

SensorDS18B20::SensorDS18B20(String _tagTS) {
  tagTS = _tagTS;
}

String SensorDS18B20::getTSName() {
  return tagTS;
}

OneWire* SensorDS18B20::_oneWire;
DallasTemperature* SensorDS18B20::_sensor;

float SensorDS18B20::captureWaterTemperature() {
  uint8_t buses[] = ONE_WIRE_BUS;
  size_t buses_length = sizeof(buses) / sizeof(buses[0]);
  
  _oneWire = (OneWire*) malloc(buses_length * sizeof(OneWire));
  _sensor = (DallasTemperature*) malloc(buses_length * sizeof(DallasTemperature));
  for (size_t i = 0; i < buses_length; i++) {
    _oneWire[i] = OneWire(buses[i]);
    _sensor[i] = DallasTemperature(&_oneWire[i]);
    _sensor[i].begin();
    _sensor[i].requestTemperatures(); 
  }
 
  for (size_t i = 0; i < buses_length; i++) {
    waterTemp = _sensor[i].getTempCByIndex(0);
    if (waterTemp == DEVICE_DISCONNECTED_C) {
      waterTemp = 0;
    }
    return waterTemp;
  }
}