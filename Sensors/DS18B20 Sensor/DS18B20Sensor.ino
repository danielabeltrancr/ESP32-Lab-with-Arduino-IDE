#include "DS18B20Sensor.h"

#define ONE_WIRE_BUS {33}     // DS180B20 GPIO

SensorDS18B20 objSensorDS18B20("Water temperature");

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print(objSensorDS18B20.getTSName());
  Serial.println(objSensorDS18B20.captureWaterTemperature());

}