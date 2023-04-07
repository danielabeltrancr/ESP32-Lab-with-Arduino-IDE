#include "SaveData.h"

const int chipSelect = 15;  // used for ESP8266

sdData objSaveData(chipSelect);

void setup() {
  Serial.begin(115200);
  delay(1000);
  objSaveData.initSD();
  objSaveData.CreateFile();
}

void loop() {
  objSaveData.SaveData();

}
