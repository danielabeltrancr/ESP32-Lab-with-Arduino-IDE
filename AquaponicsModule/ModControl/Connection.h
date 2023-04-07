#ifndef HEADER_CONNECTION_H
#define HEADER_CONNECTION_H
#include <Arduino.h>
#include <WiFi.h>

class Connection {
  public:
    Connection();
    void init_wifi();
};

#endif
