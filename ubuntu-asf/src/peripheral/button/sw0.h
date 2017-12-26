#ifndef PERIPHERAL_BUTTON_SW0_H_
#define PERIPHERAL_BUTTON_SW0_H_

#include <stdint.h>

#include "asf/asf.h"
#include "peripheral/button/gpio-button.h"

namespace peripheral {

class Sw0 : public GpioButton {
 public:
  Sw0();
  ~Sw0() final;
  auto IsPressed() const -> bool final;

 private:
  auto SetAsInput() const -> void;
  static bool instantiated_;
  const uint8_t pin_{PIN_PA15};
};

}  // namespace peripheral

#endif  // PERIPHERAL_BUTTON_SW0_H_
