#include "io1-led.h"

#include <cassert>

#include "sam.h"

namespace perhipial {

bool Io1Led::instantiated_ = false;

Io1Led::Io1Led() {
  assert(!instantiated_);
  instantiated_ = true;
  SetAsOutput();
  Off();
}

Io1Led::~Io1Led() {
  Off();
  instantiated_ = false;
}

auto Io1Led::On() const -> void {
  PORT->Group[1].OUTCLR.reg = PORT_PB02;
}

auto Io1Led::Off() const -> void {
  PORT->Group[1].OUTSET.reg = PORT_PB02;
}

auto Io1Led::Toggle() const -> void {
  PORT->Group[1].OUTTGL.reg = PORT_PB02;
}

auto Io1Led::SetAsOutput() const -> void {
  PORT->Group[1].DIRSET.reg = PORT_PB02;
}

}  // namespace perhipial
