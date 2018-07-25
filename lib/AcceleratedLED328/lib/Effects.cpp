#include "Effects.h"
#include "Pixel.h"

Effects::Effects(){
  lastRun = 0;
}

void Effects::init(){
  leftStrip.init(1, 2);
  rightStrip.init(3, 4);

  effect = &noEffect;
}

void Effects::run(Data &data){
  unsigned long currMillis = millis();
  if(currMillis - lastRun > UPDATE_DURRATION){
    lastRun = currMillis;

    this->blinkerOrEffect(leftStrip, data, data.blinker.left);
    this->blinkerOrEffect(rightStrip, data, data.blinker.right);
  }
}

bool Effects::blinkerOrEffect(Strip &strip, Data &data, bool blink){
  if(blink){
    strobe.run(strip, data);
  }else{
    effect -> run(strip, data);
  }
  strip.update();
}
