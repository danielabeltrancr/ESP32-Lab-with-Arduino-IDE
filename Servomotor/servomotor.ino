/*
 # Product: Servomotor
 # Servo Library for ESP32: https://github.com/jkb-git/ESP32Servo
*/

#include <Servo.h>

Servo servo;                        // create an object of type Servo
int spin = 0;
#define increase 'w'
#define decrease 's'
byte data;

void setup() {
  Serial.begin(115200);
  servo.attach(13);                 // pin control servo 
}

void loop() {

  while(Serial.available()){               
    data = Serial.read();  
    
    switch (data){
    case increase:   // increase
      spin++;
      spin = spin > 180 ? 180 : spin;
      /* With servo.write(degrees) we position the servo, it admits values from 0° to 180° */
      servo.write(spin);            
      Serial.print("spin: ");
      Serial.println(spin);
      break;

    case Disminuir:   // decrease
      spin--;
      spin = spin < 0 ? 0 : spin;
      /* With servo.write(degrees) we position the servo, it admits values from 0° to 180° */
      servo.write(spin);
      Serial.print("spin: ");
      Serial.println(spin);
      break;
    }            

  }
}
