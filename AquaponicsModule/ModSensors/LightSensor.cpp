#include "LightSensor.h"

LightSensor::LightSensor() {}

LightSensor::LightSensor(String _tagLS, int _pinLS) {  
  tagLS = _tagLS;
  pinLS = _pinLS;
  pinMode(pinLS, INPUT);
}

String LightSensor::getLSName() {
  return tagLS;
}

int LightSensor::captureLightValue() {
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= interval) {
    timerDelay = timepoint;
    luminosity = analogRead(pinLS);
    valLuminosity = map(luminosity, 0, 1023, 0, 100);
  }
  return valLuminosity;
}
