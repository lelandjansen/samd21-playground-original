#ifndef PERHIPIAL_LED_LED0_H_
#define PERHIPIAL_LED_LED0_H_

#include "gpio-led-interface.h"

namespace perhipial {

class Led0 : GpioLedInterface {
 public:
  Led0();
  ~Led0() final;
  auto On() const -> void final;
  auto Off() const -> void final;
  auto Toggle() const -> void final;
 private:
  auto SetAsOutput() const -> void;
  static bool instantiated_;
};

}  // namespace perhipial

#endif // PERHIPIAL_LED_LED0_H_
