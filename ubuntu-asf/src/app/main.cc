#include "asf/asf.h"
#include "peripheral/led/led0.h"

//auto main() -> int {
//  system_init();
//  delay_init();
//
//	struct port_config pin_conf;
//	port_get_config_defaults(&pin_conf);
//	pin_conf.direction = PORT_PIN_DIR_OUTPUT;
//	port_pin_set_config(PIN_PB30, &pin_conf);
//	port_pin_set_output_level(PIN_PB30, 0);
//  
//  while (true) {
//	  port_pin_toggle_output_level(PIN_PB30);
//    delay_ms(1000);
//  }
//}

int main() {
  system_init();
  delay_init();

  peripheral::Led0 led;
  while (true) {
    led.Toggle();
    delay_ms(1000);
  }
}
