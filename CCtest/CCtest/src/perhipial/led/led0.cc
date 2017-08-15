#include "led0.h"

#include <cassert>

#include "sam.h"

namespace perhipial {

bool Led0::instantiated_ = false;

Led0::Led0() {
  assert(!instantiated_);
  instantiated_ = true;
	SetAsOutput();
	Off();
}
	
Led0::~Led0() {
	Off();
  instantiated_ = false;
}
	
auto Led0::On() const -> void {
	PORT->Group[1].OUTCLR.reg = PORT_PB30;
}
	
auto Led0::Off() const -> void {
	PORT->Group[1].OUTSET.reg = PORT_PB30;
}
	
auto Led0::Toggle() const -> void {
	PORT->Group[1].OUTTGL.reg = PORT_PB30;
}
	
auto Led0::SetAsOutput() const -> void {
	PORT->Group[1].DIRSET.reg = PORT_PB30;
}

}  // namespace perhipial
