#ifndef HEADER_ESP_NOW_H
#define HEADER_ESP_NOW_H
#include <Arduino.h>
#include <SimpleEspNowConnection.h>

typedef struct dataPacket {
  int id;               //board id
  char heights[64];     //heights
  int sensorValue_1;    //light
  float sensorValue_2;  //temperature
  float sensorValue_3;  //humidity
  float sensorValue_4;  //water temperature
  float sensorValue_5;  //pH
} dataPacket;

dataPacket Data;

void transmissionComplete(const uint8_t *mac_addr, const uint8_t *incomingData, int data_len) {
  char macStr[18];
  Serial.print("Packet received from: ");
  snprintf(macStr, sizeof(macStr),"%02X:%02X:%02X:%02X:%02X:%02X",mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
  Serial.println(macStr);
  memcpy(&Data, incomingData, sizeof(Data));
  Serial.printf("Board ID %u: %u bytes\n", Data.id, data_len);
  Serial.print("Luminosity: ");
  Serial.println(Data.sensorValue_1);
  Serial.println();
  delay(1000);
}

void init_EspNow() {
  if (esp_now_init() != ESP_OK) {                 // Init ESP-NOW
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(transmissionComplete);
  Serial.println("Initialized.");
}

#endif
