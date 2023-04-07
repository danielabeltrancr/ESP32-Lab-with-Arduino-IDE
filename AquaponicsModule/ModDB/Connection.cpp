#include "Connection.h"

Connection::Connection() {}

void Connection::init_wifi() {
  Serial.println();
  Serial.println("Initializing receiver node 1...");
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println();
}
