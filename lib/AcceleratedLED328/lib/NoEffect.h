#ifndef NO_EFFECT_H
#define NO_EFFECT_H

#include "Arduino.h"
#include "Effect.h"

class NoEffect: public Effect {
  public:
    NoEffect();
    void run(Strip &strip, Data &data);

  private:

};
#endif
