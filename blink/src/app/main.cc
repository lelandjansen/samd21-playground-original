#include "perhipial/led/led0.h"
#include "util/clock.h"
#include "util/delay.h"

auto main() -> int {
  util::ClockInit();
  util::DelayInit();
  perhipial::Led0 led;
  while (true) {
    led.Toggle();
    util::DelayMilliseconds(1000);
  }
}

