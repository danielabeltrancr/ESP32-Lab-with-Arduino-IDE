/*
 # Product: NeoPixel WS2812 5050 RGB LED Strip
 # Library Adafruit_NeoPixel: https://github.com/adafruit/Adafruit_NeoPixel
*/

#include <Adafruit_NeoPixel.h>

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick

Adafruit_NeoPixel module(16, 5, NEO_GRB + NEO_KHZ800); 

void setup() {
  module.begin();
  module.show();
}

void loop() {
  module.clear();
  module.setBrightness(20);                // global brightness for the whole strip
  for (int i = 0; i < 16; i++) {
    module.setPixelColor(i, 255, 0, 255);  // position, R, G, B
    module.show();  
    //delay(10);
  }
}
