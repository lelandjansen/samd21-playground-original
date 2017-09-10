#include "perhipial/led/led0.h"
#include "util/clock.h"
#include "util/delay.h"
//#include "util/dynamic-memory.h"
//#include "util/syscalls.h"

auto main() -> int {
  util::ClockInit();
  util::DelayInit();
  perhipial::Led0 led;
  while (true) {
    led.Toggle();
    util::DelayMilliseconds(500);
  }
 }

