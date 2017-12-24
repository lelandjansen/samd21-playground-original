#include <asf.h>

int main (void) {
  system_init();
  delay_init();

	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);
	pin_conf.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(LED0, &pin_conf);
	port_pin_set_output_level(LED0, 0);
  
  while (true) {
	  port_pin_toggle_output_level(LED0);
    delay_ms(1000);
  }
}
