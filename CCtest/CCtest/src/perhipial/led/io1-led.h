#ifndef PERHIPIAL_LED_IO1_LED_H_
#define PERHIPIAL_LED_IO1_LED_H_

#include "gpio-led-interface.h"

namespace perhipial {

class Io1Led : GpioLedInterface {
  public:
  Io1Led();
  ~Io1Led() final;
  auto On() const -> void final;
  auto Off() const -> void final;
  auto Toggle() const -> void final;
  private:
  auto SetAsOutput() const -> void;
  static bool instantiated_;
};

}  // namespace perhipial

#endif // PERHIPIAL_LED_IO1_LED_H_
