#ifndef PERHIPIAL_LED_LED_GREEN_H_
#define PERHIPIAL_LED_LED_GREEN_H_

#include "pwm-led-interface.h"

namespace perhipial {

class LedGreen : PwmLedInterface {
 public:
  LedGreen();
  ~LedGreen() final;
	auto SetDutyCycle(uint8_t duty_cycle) const -> void final; 
	auto Off() const -> void final;
 private:
	auto SetAsOutput() const -> void;
	static bool instantiated_;
};

}  // namespace perhipial

#endif // PERHIPIAL_LED_LED_GREEN_H_