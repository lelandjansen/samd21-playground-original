#include "peripheral/button/sw0.h"

#include <cassert>

#include "asf/asf.h"

namespace peripheral {

bool Sw0::instantiated_ = false;

Sw0::Sw0() {
  assert(!instantiated_);  // NOLINT
  instantiated_ = true;
  SetAsInput();
}

Sw0::~Sw0() {
  instantiated_ = false;
}

auto Sw0::IsPressed() const -> bool {
  return port_pin_get_input_level(pin_);
}

auto Sw0::SetAsInput() const -> void {
  port_config pin_conf{};
  port_get_config_defaults(&pin_conf);
  pin_conf.direction = PORT_PIN_DIR_INPUT;
  port_pin_set_config(pin_, &pin_conf);
}

}  // namespace peripheral
