#ifndef PERIPHERAL_LED_IO1LED_H_
#define PERIPHERAL_LED_IO1LED_H_

#include <cstdint>

#include "asf/asf.h"
#include "peripheral/led/pwm-led.h"

namespace peripheral {

class Io1Led : public PwmLed {
 public:
  Io1Led();
  ~Io1Led() final;
  auto On() const -> void final;
  auto Off() const -> void final;
  auto SetBrightness(const uint8_t level) const -> void;

 private:
  auto SetAsPwmOutput() const -> void;
  static bool instantiated_;
  const uint8_t pin_{PIN_PB02};
};

}  // namespace peripheral

#endif  // PERHIPHERAL_LED_IO1LED_H_
