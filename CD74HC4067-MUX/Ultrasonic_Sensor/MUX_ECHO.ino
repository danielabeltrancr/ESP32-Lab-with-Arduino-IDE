#include "MUX_ECHO.h"

const int pinSIG = 13;           
const int pinS3 = 14;            
const int pinS2 = 27;            
const int pinS1 = 26;            
const int pinS0 = 25;   

Mux_Echo objMuxEcho(pinS0, pinS1, pinS2, pinS3, pinSIG);

void setup() {
  Serial.begin(115200);
  delay(1000);

}

void loop() {
  Serial.println(objMuxEcho.getHeights());
}
