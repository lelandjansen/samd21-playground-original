#include "sw0.h"

#include <cassert>

#include "sam.h"

namespace perhipial {

bool Sw0::instantiated_ = false;

Sw0::Sw0() {
  assert(!instantiated_);
  instantiated_ = true;
  SetAsInput();
}

Sw0::~Sw0() {
  instantiated_ = false;
}  
	
auto Sw0::IsPressed() const -> bool {
	return !(REG_PORT_IN0 & PORT_PA15);
}

auto Sw0::SetAsInput() const -> void {
  // With pull-up resistor
  PORT->Group[0].PINCFG[15].bit.INEN = true;
  PORT->Group[0].PINCFG[15].bit.PULLEN = true;
  PORT->Group[0].OUTSET.reg = PORT_PA15;
}

}  // namespace perhipial
