#include "servomotor.h"

ServoMotor::ServoMotor() {}

ServoMotor::ServoMotor(int _pinServo) {
  pinServo = _pinServo;
}


void ServoMotor::initServo() {
  servoMotor.attach(pinServo);
  servoMotor.write(0);
}

void ServoMotor::positive() {
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= time_1) {
    timerDelay = timepoint;
    for (int i = 0; i <= 90; i++) {
      servoMotor.write(i);
      delay(25);
    }
  }
}

void ServoMotor::negative() {
  unsigned long timepoint = millis();
  if (timepoint - timerDelay >= time_2) {
    timerDelay = timepoint;
    for (int i = 89; i > 0; i--) {
      servoMotor.write(i);
      delay(25);
    }
  }
}
