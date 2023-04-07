/*
 # Product: DHT22 sensor
 # Library DHT-sensor-library: https://github.com/adafruit/DHT-sensor-library
 # More information about the library: https://learn.adafruit.com/dht
*/

#include "DHTSensor.h"
  
const int pinDHT = 32; 
#define DHT_TYPE DHT22

DHTSensor objDHTSensor("Temperature: °C", "Humidity: %", pinDHT, DHT_TYPE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print(objDHTSensor.getTempName());
  Serial.print(",");
  Serial.println(objDHTSensor.getHumdName());
  Serial.print(objDHTSensor.captureTemperatureValue());
  Serial.print(",");
  Serial.println(objDHTSensor.captureHumidityValue());
}