#include "util/delay.h"
#include "led/led.h"

auto main() -> int {
  const auto delay = 1000;
  led::SetOutput();
  while (true) {
    led::On();
    Delay(delay);
    led::Off();
    Delay(delay);
  }
}

