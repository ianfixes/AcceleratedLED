#include <ArduinoUnitTests.h>
#include "../src/Strip.h"

unittest(set_strip_values)
{
  GodmodeState* state = GODMODE();
  state->reset();

  Strip s = Strip();
  s.init(3, 2);

  Pixel p = Pixel();
  p.set(50, 50, 50);

  s.setColor(p.hsv);
  assertEqual(30, state->digitalPin[3].toAscii(1, true).length());

  s.update();
  assertEqual(60, state->digitalPin[3].toAscii(1, true).length());

  // this is really a test of the underlying library, but whatever

  // pin 2 is the clock pin, we expect 0xAA, which is 0b10101010
  assertEqual(0xAA, (unsigned char)(state->digitalPin[2].toAscii(1, true)[0]));
  assertEqual(0xAA, (unsigned char)(state->digitalPin[2].toAscii(1, true)[1]));
  assertEqual(0xAA, (unsigned char)(state->digitalPin[2].toAscii(1, true)[2]));

  // pin 3 is the data, we expect 3 byte groups, all zeroes
  assertEqual(0, (unsigned int)(state->digitalPin[3].toAscii(1, true)[0]));
  assertEqual(0, (unsigned int)(state->digitalPin[3].toAscii(1, true)[1]));
  assertEqual(0, (unsigned int)(state->digitalPin[3].toAscii(1, true)[2]));

  // the second 30 bytes will be our pixel color.  not sure what to expect
  // but I _do_ expect it to repeat
  assertEqual(40, (unsigned int)(state->digitalPin[3].toAscii(1, true)[30]));
  assertEqual(40, (unsigned int)(state->digitalPin[3].toAscii(1, true)[31]));
  assertEqual(50, (unsigned int)(state->digitalPin[3].toAscii(1, true)[32]));
  assertEqual(40, (unsigned int)(state->digitalPin[3].toAscii(1, true)[33]));
  assertEqual(40, (unsigned int)(state->digitalPin[3].toAscii(1, true)[34]));
  assertEqual(50, (unsigned int)(state->digitalPin[3].toAscii(1, true)[35]));
}

unittest_main()
