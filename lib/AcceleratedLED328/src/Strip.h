#ifndef STRIP_H
#define STRIP_H

#include "Adafruit_WS2801.h"
#include "Pixel.h"

const uint8_t STRIP_LENGTH = 10;

class Strip {
  public:
    //Init;
    Strip();
    void init(uint8_t dataPin, uint8_t clkPin);

    //Get
    Pixel* pixel(uint8_t index);

    //Set
    void setColor(ColorHSV color);

    //Update
    void update();

  private:
    Adafruit_WS2801 strip;
    Pixel pixels[STRIP_LENGTH];

};
#endif
