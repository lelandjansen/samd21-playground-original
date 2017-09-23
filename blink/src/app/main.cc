#include "peripheral/led/led0.h"
#include "util/clock.h"
#include "util/delay.h"

auto main() -> int {
  util::ClockInit();
  util::DelayInit();
  peripheral::Led0 led;
  while (true) {
    led.Toggle();
    util::DelayMilliseconds(1000);
  }
}

