#ifndef SOLID_BLINK_H
#define SOLID_BLINK_H

#include "Arduino.h"
#include "Effect.h"

class Strobe: public Effect {
  public:
    Strobe();
    void run(Strip &strip, Data &data);

  private:
    ColorHSV color;
    bool isOn;
    uint8_t durration;
    unsigned long lastStep;

};
#endif
