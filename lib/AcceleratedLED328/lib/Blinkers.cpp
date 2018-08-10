#include "Blinkers.h"
#include "Arduino.h"

const uint8_t LEFT_BLINKER_PIN = 3;
const uint8_t RIGHT_BLINKER_PIN = 2;

Blinkers::Blinkers(){
}

void Blinkers::init(){
  leftButton.attach(LEFT_BLINKER_PIN, INPUT_PULLUP);
  leftButton.interval(1);

  rightButton.attach(RIGHT_BLINKER_PIN, INPUT_PULLUP);
  rightButton.interval(1);
}
void Blinkers::run(Data &data){
  leftButton.update();
  rightButton.update();

  data.blinker.left = !leftButton.read();
  data.blinker.right = !rightButton.read();
}

