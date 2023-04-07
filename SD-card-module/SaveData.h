#ifndef SAVEDATA_h
#define SAVEDATA_h
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

class sdData {
  public:
    sdData();
    sdData(int chipSelect);
    void initSD();
    void CreateFile();
    void SaveData();

  private:
    int chipSelect;
    File dataFile;
};

#endif
