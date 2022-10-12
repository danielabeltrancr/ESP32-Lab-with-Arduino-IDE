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
  int luminosity = 0;
  static unsigned long timepoint = millis();
  if (millis() - timepoint > timerDelay) {
    timepoint = millis();
    luminosity = analogRead(pinLS);
    valLuminosity = map(luminosity, 0, 1023, 0, 100);
  }
  return valLuminosity;
}