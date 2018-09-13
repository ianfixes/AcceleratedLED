#ifndef DATA_H
#define DATA_H

const uint16_t HUE_ORANGE = ((uint32_t)17*0xFF/360) << 8;

struct Acceleration16{
  int16_t x;
  int16_t y;
  int16_t z;
};

struct Blinker{
  bool right;
  bool left;
};

struct Data {
  Acceleration16 acceleration;
  int16_t temperature;
  Blinker blinker;
};
#endif
