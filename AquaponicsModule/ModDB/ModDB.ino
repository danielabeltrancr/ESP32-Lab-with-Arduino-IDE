#include "Connection.h"
#include "EspNow.h"
#include "ModuleSD.h"

Connection objCon;
ModuleSD objModuleSD(pinChipSelect);

void setup() {
  Serial.begin(115200);
  objCon.init_wifi();
  init_EspNow();
  objModuleSD.initSD();
  objModuleSD.CreateFile();
}

void loop() {

}
