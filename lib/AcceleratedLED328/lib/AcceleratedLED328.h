#ifndef ACCELERATED_LED_H
#define ACCELERATED_LED_H

#include "Effects.h"
#include "Blinkers.h"
#include "Data.h"
#include <ADXL362.h>

//#define PRINT_ACCELEROMETER

class AcceleratedLED328{
  public:
    AcceleratedLED328();
    void init();
    void run();

  private:
    Data data;
    Blinkers blinkers;
    Effects effects;
    ADXL362 accelerometer;
};

#endif
