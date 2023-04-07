#include "MUX_TRIGGER.h"

const int pinSIG = 18;           
const int pinS3 = 5;            
const int pinS2 = 17;            
const int pinS1 = 16;            
const int pinS0 = 4;   

Mux_Trigger objMux_Trigger(pinS0, pinS1, pinS2, pinS3, pinSIG);

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  objMux_Trigger.Trigger();
}
