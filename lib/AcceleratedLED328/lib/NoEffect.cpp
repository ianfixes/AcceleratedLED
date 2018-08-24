#include "NoEffect.h"

NoEffect::NoEffect(){
}

void NoEffect::run(Strip &strip, Data &data){
  ColorHSV color = ColorHSV(0xFF, 0xFF, 0x00);
  strip.setColor(color);
}




