#include <AlaLedRgb.h>
#define RED 3
#define BLUE 6
#define GREEN 9

AlaLedRgb rgbLed;

void setup() {
  // put your setup code here, to run once:
  rgbLed.initPWM(RED, GREEN, BLUE);
  rgbLed.setBrightness(0x66FF44);
  rgbLed.setAnimation(ALA_FADECOLORSLOOP, 3000, alaPalRgb);
}

void loop() {
  // put your main code here, to run repeatedly:
  rgbLed.runAnimation()
}
