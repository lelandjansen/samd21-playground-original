#include "button.h"

#include "sam.h"

namespace perhipial {

Button::Button() {
	// Set input with pull-up resistor
	PORT->Group[0].PINCFG[15].bit.INEN = true;
	PORT->Group[0].PINCFG[15].bit.PULLEN = true;
	PORT->Group[0].OUTSET.reg = PORT_PA15;
}
	
auto Button::IsPressed() const -> bool {
	return !(REG_PORT_IN0 & PORT_PA15);
}

}  // namespace perhipial
