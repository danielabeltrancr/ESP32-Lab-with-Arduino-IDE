#ifndef HEADER_ESP_NOW_H
#define HEADER_ESP_NOW_H
#include <Arduino.h>
#include <SimpleEspNowConnection.h>

#define BOARD_ID 1  
uint8_t receiverAddress1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t receiverAddress2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t receiverAddress3[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

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

esp_now_peer_info_t peerInfo; 

void transmissionComplete(const uint8_t *mac_addr, esp_now_send_status_t status) {    
  char macStr[18];
  Serial.print("Packet from: ");
  snprintf(macStr, sizeof(macStr),"%02X:%02X:%02X:%02X:%02X:%02X",mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
  Serial.print(macStr);       
  Serial.print(" send status: "); 
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void init_EspNow() {
  if (esp_now_init() != ESP_OK) {                      // Init ESP-NOW
    Serial.println("Error initializing ESP-NOW");
    return;
  }
    
  esp_now_register_send_cb(transmissionComplete);
  
  peerInfo.channel = 0;                               // Register peer
  peerInfo.encrypt = false;
  // Register first peer
  memcpy(peerInfo.peer_addr, receiverAddress1, 6);    
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {      
    Serial.println("Failed to add peer");
    return;
  }  
  // Register second peer
  memcpy(peerInfo.peer_addr, receiverAddress2, 6);    
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {      
    Serial.println("Failed to add peer");
    return;
  } 
  // Register third peer
  memcpy(peerInfo.peer_addr, receiverAddress3, 6);    
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {      
    Serial.println("Failed to add peer");
    return;
  } 
}

#endif
