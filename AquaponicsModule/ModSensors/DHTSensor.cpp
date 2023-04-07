#include "DHTSensor.h"

DHTSensor::DHTSensor(String _tagTemp, String _tagHumd, int _pinDHT, int _DHT_TYPE) : dht(_pinDHT, _DHT_TYPE) {
  tagTemp = _tagTemp;
  tagHumd = _tagHumd;
  pinMode(_pinDHT, INPUT);
}

String DHTSensor::getTempName() {
  return tagTemp;
}

String DHTSensor::getHumdName() {
  return tagHumd;
}

float DHTSensor::captureTemperatureValue() {
  dht.begin();
  delay(1000);
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= interval) {
    timerDelay = timepoint;
    temperature = dht.readTemperature();
    if (isnan(temperature)) {
      temperature = dht.readTemperature();
    }
  }
  return temperature;
}

float DHTSensor::captureHumidityValue() {
  dht.begin();
  delay(1000);
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= interval) {
    timerDelay = timepoint;
    humidity = dht.readHumidity();
    if (isnan(humidity)) {
      humidity = dht.readHumidity();
    }
  }
  return humidity;
}
