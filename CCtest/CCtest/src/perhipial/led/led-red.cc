#include "led-red.h"

#include <cassert>

#include "sam.h"
#include "../../util/wait.h"

namespace perhipial {

bool LedRed::instantiated_ = false;

LedRed::LedRed() {
  assert(!instantiated_);
  instantiated_ = true;
  SetAsOutput();
  Off();
}

LedRed::~LedRed() {
  Off();
  instantiated_ = false;
}

auto LedRed::On() const -> void {
  PORT->Group[0].OUTCLR.reg = PORT_PA10;
}

auto LedRed::Off() const -> void {
  PORT->Group[0].OUTSET.reg = PORT_PA10;
}

auto LedRed::Toggle() const -> void {
  PORT->Group[0].OUTTGL.reg = PORT_PA10;
}

auto LedRed::SetAsOutput() const -> void {
  PORT->Group[0].DIRSET.reg = PORT_PA10;
}
  
}  // namespace perhipial
