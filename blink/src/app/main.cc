#include "util/clock.h"
#include "util/delay.h"
#include "perhipial/led/led0.h"

auto main() -> int {
  util::ClockInit();
  util::DelayInit();
  const auto delay = 1000;
  perhipial::Led0 led;
  while (true) {
    led.Toggle();
    util::DelayMilliseconds(delay);
  }
}

