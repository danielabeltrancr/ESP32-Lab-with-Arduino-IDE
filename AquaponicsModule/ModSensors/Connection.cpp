#include "Connection.h"

Connection::Connection() {}

void Connection::init_wifi() {
  Serial.println();
  Serial.println("Initializing sender node...");
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
}
