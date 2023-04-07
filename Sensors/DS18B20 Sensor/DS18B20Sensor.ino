/*
 # Product: DS18B20
 # Library One Wire: https://github.com/PaulStoffregen/OneWire
 # More information about the library: http://www.pjrc.com/teensy/td_libs_OneWire.html
 # Library Dallas Temperature: https://github.com/milesburton/Arduino-Temperature-Control-Library
 # More information about the library: http://www.milesburton.com/Dallas_Temperature_Control_Library
*/

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