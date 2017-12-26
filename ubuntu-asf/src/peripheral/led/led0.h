#ifndef PERIPHERAL_LED_LED0_H_
#define PERIPHERAL_LED_LED0_H_

#include <stdint.h>

#include "asf/asf.h"
#include "peripheral/led/gpio-led.h"

namespace peripheral {

class Led0 : public GpioLed {
 public:
  Led0();
  ~Led0() final;
  auto On() const -> void final;
  auto Off() const -> void final;
  auto Toggle() const -> void final;

 private:
  auto SetAsOutput() const -> void;
  static bool instantiated_;
  const uint8_t pin_{PIN_PB30};
};

}  // namespace peripheral

#endif  // PERHIPHERAL_LED_LED0_H_
