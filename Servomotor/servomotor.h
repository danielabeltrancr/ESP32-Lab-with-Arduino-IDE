#ifndef SERVOMOTOR_CONTROL_H
#define SERVOMOTOR_CONTROL_H
#include <Arduino.h>
#include <Servo.h>
#include "Config.h"

class ServoMotor {
  public:
    ServoMotor();
    ServoMotor(int _pinServo);
    void initServo();
    void positive();
    void negative();

  private:
    int pinServo;
    unsigned long timerDelay = 0;
    long time_1 = 300000;           // 1000 = 1.008 seconds
    long time_2 = 15000;            // 1000 = 1.008 seconds
    Servo servoMotor; 
};

#endif
