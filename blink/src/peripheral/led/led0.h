#ifndef PERIPHERAL_LED_LED0_H_ 
#define PERIPHERAL_LED_LED0_H_ 

#include "peripheral/led/gpio-led-interface.h"

namespace peripheral {

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

}  // namespace peripheral

#endif  // PERHIPHERAL_LED_LED0_H_
