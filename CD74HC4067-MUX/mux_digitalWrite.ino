// Ultrasonic sensor with mux

#include <CD74HC4067.h>
               // s0 s1 s2 s3
CD74HC4067 my_mux(33, 25, 26, 27);     // create a new CD74HC4067 object with its four control pins
const int g_common_pin = 32;           // select a pin to share with the 16 channels of the CD74HC4067

void setup() {
  pinMode(g_common_pin, OUTPUT);       // set the initial mode of the common pin.
                                       // This can be changed in loop() for for each channel.
  
  digitalWrite(g_common_pin, LOW);
  Serial.begin(115200);                // initialize serial communications at 115200 bps
}

void loop() {
  for (int i = 0; i < 16; i++) {
    my_mux.channel(i);                                                                                         
    Serial.print("channel = ");
    Serial.println(i);
    digitalWrite(g_common_pin, HIGH);
    delay(1000);
    digitalWrite(g_common_pin, LOW);
  }
}
