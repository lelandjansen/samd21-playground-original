#include "peripheral/led/led0.h"

#include <cassert>

#include "asf/asf.h"

namespace peripheral {

bool Led0::instantiated_ = false;

Led0::Led0() {
  assert(!instantiated_);  // NOLINT
  instantiated_ = true;
  SetAsOutput();
  Off();
}

Led0::~Led0() {
  Off();
  instantiated_ = false;
}

auto Led0::On() const -> void { port_pin_set_output_level(pin_, true); }

auto Led0::Off() const -> void { port_pin_set_output_level(pin_, false); }

auto Led0::Toggle() const -> void { port_pin_toggle_output_level(pin_); }

auto Led0::SetAsOutput() const -> void {
  port_config pin_conf{};
  port_get_config_defaults(&pin_conf);
  pin_conf.direction = PORT_PIN_DIR_OUTPUT;
  port_pin_set_config(pin_, &pin_conf);
}

}  // namespace peripheral
