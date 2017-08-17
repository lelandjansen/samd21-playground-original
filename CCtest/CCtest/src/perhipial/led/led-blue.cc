#include "led-blue.h"

#include <cassert>

#include "sam.h"
#include "../../util/wait.h"

namespace perhipial {

bool LedBlue::instantiated_ = false;

LedBlue::LedBlue() {
  assert(!instantiated_);
  instantiated_ = true;
  SetAsOutput();
  Off();
}

LedBlue::~LedBlue() {
  Off();
  instantiated_ = false;
}

auto LedBlue::On() const -> void {
  PORT->Group[0].OUTCLR.reg = PORT_PA20;
}

auto LedBlue::Off() const -> void {
  PORT->Group[0].OUTSET.reg = PORT_PA20;
}

auto LedBlue::Toggle() const -> void {
  PORT->Group[0].OUTTGL.reg = PORT_PA20;
}

auto LedBlue::SetAsOutput() const -> void {
  PORT->Group[0].DIRSET.reg = PORT_PA20;
}
  
}  // namespace perhipial
