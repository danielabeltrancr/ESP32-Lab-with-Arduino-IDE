/*
 *           ESP8266  |  ESP32 WROOM
 * MOSI --->   13     |       23    
 * MISO --->   12     |       19
 * SCK  --->   14     |       18
 * SS   --->   15     |        5
 */

void setup() {
  Serial.begin(115200);
  Serial.println(MOSI);
  Serial.println(MISO);
  Serial.println(SCK);
  Serial.println(SS);

}

void loop() {
  // put your main code here, to run repeatedly:

}
