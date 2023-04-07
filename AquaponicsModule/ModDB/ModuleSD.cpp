#include "ModuleSD.h"

ModuleSD::ModuleSD(int _pinChipSelect) {
  pinChipSelect = _pinChipSelect;
}

void ModuleSD::initSD() {
  while (!Serial) {}
  Serial.println("Initializing SD card... ");
  if(!SD.begin(pinChipSelect)) {
    Serial.println("ERROR - SD card initialization failed!");
    while(1);
  }
  Serial.println("Initialization done"); 
}

void ModuleSD::CreateFile() {
  if(!SD.exists("DataBase_Acuaponia.csv")){
    dataFile = SD.open("DataBase_Acuaponia.csv", FILE_WRITE);
    if(dataFile) {
      Serial.println("New file, writing header(row 1)");
      dataFile.println("Light,Temperature,Humidity,Water Temperature,pH,Height 1,Height 2,Height 3,Height 4,Height 5,Height 6,Height 7,Height 8,Height 9,Height 10,Height 11,Height 12,Height 13,Height 14,Height 15,Height 16");
      dataFile.close();
    } else {
      Serial.println("Error opening DataBase_Acuaponia.csv");
    }
  }
}
