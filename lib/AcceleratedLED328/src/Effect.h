#ifndef EFFECT_H
#define EFFECT_H

#include "Strip.h"
#include "Data.h"

class Effect{
  public:
    Effect();
    virtual void run(Strip &strip, Data &data);
};
#endif
