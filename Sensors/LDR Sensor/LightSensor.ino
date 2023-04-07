/*
 # Product: LDR
*/

#include "LightSensor.h"

const int pinLS = 36;       // LDR GPIO 

LightSensor objLightSensor("Light", pinLS);

void setup() {
  analogReadResolution(10);  // for ESP32
  Serial.begin(115200);
}

void loop() {
  Serial.println(objLightSensor.getLSName());
  Serial.print(objLightSensor.captureLightValue());
}

