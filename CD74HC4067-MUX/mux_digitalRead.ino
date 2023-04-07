#include <CD74HC4067.h>
                 // s0 s1 s2 s3
CD74HC4067 my_mux(33, 25, 26, 27);  // create a new CD74HC4067 object with its four control pins
const int g_common_pin = 32;        // select a pin to share with the 16 channels of the CD74HC4067

int val = 0;

void setup() {
  pinMode(g_common_pin, INPUT);     // set the initial mode of the common pin.
                                    // This can be changed in loop() for for each channel.
  Serial.begin(115200);             // initialize serial communications at 115200 bps
}

void loop() {
  for (int i = 0; i < 16; i++) {
    val = digitalRead(g_common_pin);
    my_mux.channel(i);
    Serial.print("channel = ");
    Serial.print(i);
    Serial.print(" val= ");
    Serial.println(val);
    delay(100);
  }
}
