#include "AcceleratedLED328.h"

/*
 * Connect SCLK, MISO, MOSI, and CSB of ADXL362 to
 * SCLK, MISO, MOSI, and DP 10 of Arduino
 */

AcceleratedLED328::AcceleratedLED328(){
}

void AcceleratedLED328::init(){
  effects.init();
  blinkers.init();

  //accelerometer.setRange(ADXL362_4G);
  accelerometer.begin(10);
  accelerometer.beginMeasure();
}

void AcceleratedLED328::run(){
  accelerometer.readXYZTData(
      data.acceleration.x,
      data.acceleration.y,
      data.acceleration.z,
      data.temperature);

#ifdef PRINT_ACCELEROMETER
  Serial.print(data.acceleration.x); Serial.print(" ");
  Serial.print(data.acceleration.y); Serial.print(" ");
  Serial.print(data.acceleration.z); Serial.print(" ");
  Serial.print(data.temperature); Serial.print(" ");
  Serial.print("\n");
#endif

  blinkers.run(data);
  effects.run(data);
}
