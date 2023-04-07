#include "DS18B20Sensor.h"

DS18B20Sensor::DS18B20Sensor() {}

DS18B20Sensor::DS18B20Sensor(String _tagTS) {
  tagTS = _tagTS;
}

String DS18B20Sensor::getTSName() {
  return tagTS;
}

OneWire* DS18B20Sensor::_oneWire;
DallasTemperature* DS18B20Sensor::_sensor;

float DS18B20Sensor::captureWaterTemperature() {
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
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= interval) {
    timerDelay = timepoint;
    for (size_t i = 0; i < buses_length; i++) {
      waterTemp = _sensor[i].getTempCByIndex(0);
      if (waterTemp == DEVICE_DISCONNECTED_C) {
        waterTemp = -127;      // -127 indicates that the sensor is disconnected
      }
    }
    return waterTemp;
  }
}
