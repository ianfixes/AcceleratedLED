#ifndef BUTTON_H
#define BUTTON_H

#include <Bounce2.h>
#include "Data.h"

class Blinkers {
  public:
    Blinkers();
    void init();
    void run(Data &data);

  private:
    Bounce leftButton;
    Bounce rightButton;

};

#endif
