#include "Effects.h"
#include "Pixel.h"

Effects::Effects(){
  lastRun = 0;
}

#define L_DO 6
#define L_BO 7

#define R_DO 4
#define R_BO 5

void Effects::init(){
  leftStrip.init(L_DO, L_BO);
  rightStrip.init(R_DO, L_BO);

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
