#include "Connection.h"

Connection::Connection() {}

void Connection::init_wifi() {
  Serial.println();
  Serial.println("Initializing receiver node 2...");
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  Serial.println();
  WiFi.mode(WIFI_STA);
}
