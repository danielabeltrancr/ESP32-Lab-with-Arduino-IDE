#include "Lights_Fish.h"

LightsFishTank::LightsFishTank(int _pixels2, int _pinLED2) : moduleFish(_pixels2, _pinLED2, NEO_GRB + NEO_KHZ800) {
  pixels2 = _pixels2;
  pinLED2 = _pinLED2;
}

void LightsFishTank::initLights() {
    moduleFish.begin();
    moduleFish.show();
}

void LightsFishTank::Lights_On() {
  moduleFish.clear();
  moduleFish.setBrightness(20);                      
  for (int pixel = 0; pixel < 16; pixel++) {
    moduleFish.setPixelColor(pixel, 133, 193, 233);  
    moduleFish.show();  
  }
}
