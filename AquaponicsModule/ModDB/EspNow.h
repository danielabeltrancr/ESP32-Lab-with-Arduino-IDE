#ifndef HEADER_ESP_NOW_H
#define HEADER_ESP_NOW_H
#include <Arduino.h>
#include <SimpleEspNowConnection.h>
#include <SD.h>

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

void transmissionComplete(uint8_t *mac_addr, uint8_t *incomingData, uint8_t data_len) {
  char macStr[18];
  Serial.print("Packet received from: ");
  snprintf(macStr, sizeof(macStr),"%02X:%02X:%02X:%02X:%02X:%02X",mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
  Serial.println(macStr);
  memcpy(&Data, incomingData, sizeof(Data));
  Serial.printf("Board ID %u: %u bytes\n", Data.id, data_len);
  /*Serial.print("Luminosity: ");
  Serial.println(Data.sensorValue_1);
  Serial.print("Temperature: ");
  Serial.println(Data.sensorValue_2);
  Serial.print("Humidity: ");
  Serial.println(Data.sensorValue_3);
  Serial.print("Water temeprature: ");
  Serial.println(Data.sensorValue_4);
  Serial.print("pH: ");
  Serial.println(Data.sensorValue_5);
  Serial.print("Heights: ");
  Serial.println(Data.heights);
  Serial.println();*/
  
  String dataString = "";
  dataString += String(Data.sensorValue_1);
  dataString += ",";
  dataString += String(Data.sensorValue_2);
  dataString += ",";
  dataString += String(Data.sensorValue_3);
  dataString += ",";
  dataString += String(Data.sensorValue_4);
  dataString += ",";
  dataString += String(Data.sensorValue_5);
  dataString += ",";
  dataString += String(Data.heights);
  Serial.println();

  File dataFile = SD.open("DataBase_Acuaponia.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
  } else {
    Serial.println("Error opening DataBase_Acuaponia.csv");
  }
  delay(1000);
}

void init_EspNow() {
  if (esp_now_init() != 0) {                       // Init ESP-NOW
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(transmissionComplete);
  Serial.println("Initialized ESP-NOW");
}

#endif
