#ifndef EFFECTS_H
#define EFFECTS_H

#include "Effect.h"
#include "NoEffect.h"
#include "Strobe.h"

const uint8_t UPDATE_DURRATION = 5;

class Effects{
  public:
    Effects();
    void init();
    void run(Data &data);

  private:
    unsigned long lastRun;

    Strip leftStrip;
    Strip rightStrip;

    Effect* effect;
    NoEffect noEffect;
    Strobe strobe;

    bool blinkerOrEffect(Strip &strip, Data &data, bool blink);
};
#endif
