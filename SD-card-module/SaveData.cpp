#include "SaveData.h"

sdData::sdData(int _chipSelect) {
  chipSelect = _chipSelect;
}

void sdData::initSD() {
  while (!Serial) {
  }
  Serial.println("Initializing SD card... ");
  if (!SD.begin(chipSelect)) {
    Serial.println("Initialization failed!");
    while (1);
  }
  Serial.println("Initialization done");
}

void sdData::CreateFile() {
  if(!SD.exists("test.csv")){
    dataFile = SD.open("test.csv", FILE_WRITE);
    if(dataFile) {
      Serial.println("New file, Writing header(row 1)");
      dataFile.println("Light,Temperature,Humidity,pH");
      dataFile.close();
    } else {
      Serial.println("Error opening test.csv");
    }
  }
}

void sdData::SaveData() {
  String dataString = "";
  int light = random(1,100);
  float temp = random(0,50);
  float humd = random(0,100);
  float pH = random(0,14);
  
  dataString += String(light);
  dataString += ",";
  dataString += String(temp);
  dataString += ",";
  dataString += String(humd);
  dataString += ",";
  dataString += String(pH);
  //dataString += ",";

  dataFile = SD.open("test.csv", FILE_WRITE);

  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
  } else {
    Serial.println("Error opening test.csv");
  }
  delay(1000);
}
