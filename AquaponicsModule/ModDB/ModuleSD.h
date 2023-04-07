#ifndef MODULE_SD_H
#define MODULE_SD_H
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "Config.h"

class ModuleSD {
  public:
    ModuleSD();
    ModuleSD(int _pinChipSelect);
    void initSD();
    void CreateFile();

  private:
    int pinChipSelect;
    File dataFile;
};

#endif
