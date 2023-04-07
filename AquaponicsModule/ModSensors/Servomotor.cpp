#include "Servomotor.h"

ServoMotor::ServoMotor() {}

ServoMotor::ServoMotor(int _pinServo) {
  pinServo = _pinServo;
}

void ServoMotor::initServo() {
  servoMotor.attach(pinServo);
  servoMotor.write(0);
}

void ServoMotor::downSensor() {
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= interval) {
    timerDelay = timepoint;
    for (int posDegrees = 1; posDegrees <= 90; posDegrees++) {
      servoMotor.write(posDegrees);
      delay(25);
    }
  }
}

void ServoMotor::upSensor() {
  delay(5000);
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= interval) {
    timerDelay = timepoint;
    for (int posDegrees = 89; posDegrees > 1; posDegrees--) {
      servoMotor.write(posDegrees);
      delay(25);
    }
  }
}
