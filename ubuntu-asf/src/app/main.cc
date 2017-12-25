#include "asf/asf.h"
#include "peripheral/led/led0.h"

auto main() -> int {
  system_init();
  delay_init();
  peripheral::Led0 led;
  while (true) {
    led.Toggle();
    delay_ms(1000);
  }
}
