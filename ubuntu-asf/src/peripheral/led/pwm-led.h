#ifndef PERIPHERAL_LED_PWM_LED_H_
#define PERIPHERAL_LED_PWM_LED_H_

#include <cstdint>

namespace peripheral {

class PwmLed {
 public:
  PwmLed() = default;
  virtual ~PwmLed() = default;
  virtual auto On() const -> void = 0;
  virtual auto Off() const -> void = 0;
  virtual auto SetBrightness(const uint8_t level) const -> void = 0;
 private:
  PwmLed(const PwmLed&) = delete;
  PwmLed& operator=(const PwmLed&) = delete;
};

}  // namespace peripheral

#endif  // PERIPHERAL_LED_PWM_LED_H_
