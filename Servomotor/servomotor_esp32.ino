/*
 # Product: Servomotor
 # Servo Library for ESP32: https://github.com/jkb-git/ESP32Servo
*/

#include "servomotor.h"

ServoMotor objServo(pinServo);

void setup() {
  Serial.begin(115200);
  objServo.initServo();
}
 
void loop() {
  objServo.positive();
  objServo.negative();
}
