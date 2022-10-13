#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#else
  #error This board is not supported
#endif

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Serial.println();
  Serial.println(WiFi.macAddress());
}

void loop() {
  
}