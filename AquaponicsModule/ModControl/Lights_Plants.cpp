#include "Lights_Plants.h"

LightsPlants::LightsPlants(int _pixels1, int _pinLED1) : modulePlants(_pixels1, _pinLED1, NEO_GRB + NEO_KHZ800) {
  pixels1 = _pixels1;
  pinLED1 = _pinLED1;
}

void LightsPlants::initLights() {
    modulePlants.begin();                              
    modulePlants.show();
}

void LightsPlants::Default_Lights() {
  modulePlants.clear();                                
  modulePlants.setBrightness(20);                      
  for (int pixel = 0; pixel < 16; pixel++) {
    modulePlants.setPixelColor(pixel, 200, 122, 197); 
    modulePlants.show();  
  }
}

void LightsPlants::Lights_Off() {
  modulePlants.clear();
  for (int pixel = 0; pixel < 16; pixel++) {
    modulePlants.setPixelColor(pixel, 0, 0, 0);      
    modulePlants.show();   
  }
}
