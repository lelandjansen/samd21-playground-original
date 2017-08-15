#ifndef PERHIPIAL_BUTTON_GPIO_BUTTON_INTERFACE_H_
#define PERHIPIAL_BUTTON_GPIO_BUTTON_INTERFACE_H_

namespace perhipial {

class GpioButtonInterface {
 public:
  GpioButtonInterface() = default;
  virtual ~GpioButtonInterface() = default;
  virtual auto IsPressed() const -> bool = 0;
 private:
  GpioButtonInterface(const GpioButtonInterface&) = delete;
  GpioButtonInterface& operator=(const GpioButtonInterface&) = delete;
};

}  // namespace perhipial

#endif // PERHIPIAL_BUTTON_GPIO_BUTTON_INTERFACE_H_
