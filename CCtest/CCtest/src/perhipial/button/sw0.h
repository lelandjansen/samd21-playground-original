#ifndef PERHIPIAL_BUTTON_SW0_H_
#define PERHIPIAL_BUTTON_SW0_H_

#include "gpio-button-interface.h"

namespace perhipial {
	
class Sw0 : GpioButtonInterface {
 public:
	Sw0();
  ~Sw0() final;
	auto IsPressed() const -> bool final;
 private:
  auto SetAsInput() const -> void;
  static bool instantiated_;
};
	
}  // namespace perhipial

#endif // PERHIPIAL_BUTTON_SW0_H_
