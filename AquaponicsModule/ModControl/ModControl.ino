#include "Connection.h"
#include "Control.h"
#include "EspNow.h"
#include "Lights_Fish.h"
#include "MuxTrigger.h"

Connection objCon;
LightsFishTank objLightsFish(pixels2, pinLED2);
Mux_Trigger objMuxTrigger(pinS0, pinS1, pinS2, pinS3, pinSIG);

void setup() {
  Serial.begin(115200);
  objCon.init_wifi();
  init_EspNow();
  objLightsFish.initLights();
  objLightsPlants.initLights();
}

void loop() {
  Control();
  objLightsFish.Lights_On();
  objMuxTrigger.Trigger();
}
