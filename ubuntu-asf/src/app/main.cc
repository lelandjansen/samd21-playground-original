#include "asf/asf.h"
#include "peripheral/button/sw0.h"
#include "peripheral/led/led0.h"

auto main() -> int {
  system_init();
  delay_init();
  peripheral::Sw0 button;
  peripheral::Led0 led;
  while (true) {
    button.IsPressed() ? led.On() : led.Off();
  }
}
