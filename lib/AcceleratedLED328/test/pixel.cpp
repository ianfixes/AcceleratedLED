#include <ArduinoUnitTests.h>
#include "../src/Pixel.h"

unittest(set_pixel_values)
{
  Pixel p = Pixel();
  assertEqual(255, p.color());
  p.set(1, 10, 100);
  assertEqual(6250596, p.color());
  p.set(0, 0, 0);
  assertEqual(0, p.color());
  p.set(100, 10, 1);
  assertEqual(1, p.color());
}

unittest_main()
