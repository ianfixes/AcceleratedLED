#include <Adafruit_WS2801.h>
#include <AcceleratedLED328.h>

#define DEBUG

AcceleratedLED328 mainProcess;

void setup(){

  #ifdef DEBUG
  Serial.begin(115200);
  #endif

  mainProcess.init();
}

void loop(){
  mainProcess.run();
}
