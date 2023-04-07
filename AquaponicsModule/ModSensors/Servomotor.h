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
    void upSensor();
    void downSensor();      

  private:
    int pinServo;
    unsigned long timerDelay = 0;
    long interval = 3600000; //3600000 = 1 hour  -->  1000 = 1.008 seconds
    Servo servoMotor; 
};

#endif
