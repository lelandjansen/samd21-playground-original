#include "led.h"

#include "sam.h"

namespace perhipial {

Led::Led(int32_t group, int32_t port) : group_(group), port_(port) {
	SetAsOutput();
	Off();
}
	
Led::~Led() {
	Off();
}
	
auto Led::On() const -> void {
	PORT->Group[group_].OUTCLR.reg = port_;
}
	
auto Led::Off() const -> void {
	PORT->Group[group_].OUTSET.reg = port_;
}
	
auto Led::Toggle() const -> void {
	PORT->Group[group_].OUTTGL.reg = port_;
}
	
auto Led::SetAsOutput() const -> void {
	PORT->Group[group_].DIRSET.reg = port_;
}

}  // namespace perhipial
