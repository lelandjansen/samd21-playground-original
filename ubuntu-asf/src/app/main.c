#include "third-party/asf/asf.h"

int main(void) {
	system_init();
	delay_init();

	struct port_config pin;
	port_get_config_defaults(&pin);
	pin.direction = PORT_PIN_DIR_OUTPUT;

	port_pin_set_config(LED0_PIN, &pin);
	port_pin_set_output_level(LED0_PIN, LED0_INACTIVE);

	while (true) {
		port_pin_toggle_output_level(LED0_PIN);
		delay_ms(1000);
	}
}
