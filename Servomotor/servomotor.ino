#include <Servo.h>

Servo servo;                        // create an object of type Servo
int Giro = 0;
#define Aumentar 'w'
#define Disminuir 's'
byte Dato;

void setup() {
  Serial.begin(115200);
  servo.attach(13);                 // pin control servo 
}

void loop() {

  while(Serial.available()){               
    Dato = Serial.read();  
    
    switch (Dato){
    case Aumentar:   // increase
      Giro++;
      Giro = Giro>180?180:Giro;
      /* With servo.write(degrees) we position the servo, it admits values from 0° to 180° */
      servo.write(Giro);            
      Serial.print("Giro: ");
      Serial.println(Giro);
      break;

    case Disminuir:   // decrease
      Giro--;
      Giro = Giro<0?0:Giro;
      /* With servo.write(degrees) we position the servo, it admits values from 0° to 180° */
      servo.write(Giro);
      Serial.print("Giro: ");
      Serial.println(Giro);
      break;
    }            

  }
}
