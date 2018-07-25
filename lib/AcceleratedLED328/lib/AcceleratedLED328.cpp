#include "AcceleratedLED328.h"

AcceleratedLED328::AcceleratedLED328(){
}

void AcceleratedLED328::init(){
  effects.init();
  blinkers.init();
  accelerometer.setRange(ADXL362_4G);
  accelerometer.begin(10);
  accelerometer.beginMeasure();
}

void AcceleratedLED328::run(){
  accelerometer.readXYZTData(
      data.acceleration.x,
      data.acceleration.y,
      data.acceleration.y,
      data.temperature);

#ifdef PRINT_ACCELEROMETER
  Serial.print(data.acceleration.x); Serial.print(" ");
  Serial.print(data.acceleration.y); Serial.print(" ");
  Serial.print(data.acceleration.z); Serial.print(" ");
  Serial.print("\n");
#endif

  blinkers.run(data);
  effects.run(data);
}
