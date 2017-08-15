#ifndef PERHIPIAL_LED_PWM_LED_H_
#define PERHIPIAL_LED_PWM_LED_H_

#include <cstdint>

namespace perhipial {

class PwmLedInterface {
 public:
  PwmLedInterface() = default;
  virtual ~PwmLedInterface() = default;
  virtual auto SetDutyCycle(uint8_t duty_cycle) const -> void = 0;
  virtual auto Off() const -> void = 0;
 private:
  PwmLedInterface(const PwmLedInterface&) = delete;
  PwmLedInterface& operator=(const PwmLedInterface&) = delete;
};

}  // perhipial

#endif // PERHIPIAL_LED_PWM_LED_H_