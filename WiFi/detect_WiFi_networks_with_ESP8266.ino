#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  // Client mode
  WiFi.mode(WIFI_STA);
}

void loop() {
  Serial.println("");

  // Get the number of networks found
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" networks found");

  // Networks found (SSID and RSSI) are printed
  for (int i = 0; i < n; i++){
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" (");
    Serial.print(WiFi.RSSI(i));
    Serial.println(")");
    delay(100);
  }

  delay(5000);
}
