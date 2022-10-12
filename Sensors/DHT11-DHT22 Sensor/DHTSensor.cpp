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
  static unsigned long timepoint = millis();
  if (millis() - timepoint > timerDelay) {
    timepoint = millis();
    temperature = dht.readTemperature();
    if (isnan(temperature)){
      temperature = dht.readTemperature();
    }
  }
  return temperature;
}

float DHTSensor::captureHumidityValue() {
  dht.begin();
  delay(1000);
  static unsigned long timepoint = millis();
  if (millis() - timepoint > timerDelay) {
    timepoint = millis();
    humidity = dht.readHumidity();
    if (isnan(humidity)){
      humidity = dht.readHumidity();
    }
  }
  return humidity;
}