#include "Strobe.h"


Strobe::Strobe(){
  durration = 200;
  isOn = false;
}

void Strobe::run(Strip &strip, Data &data){
  unsigned long currMillis = millis();
  if( currMillis - lastStep < durration ) { return; }
  lastStep = currMillis;

  isOn = !isOn;

  ColorHSV color;
  if(isOn){
    color = ColorHSV(HUE_ORANGE, 0xFF, 0xFF);
  }else{
    color = ColorHSV(0xFF, 0xFF, 0x00);
  }
  strip.setColor(color);

}



