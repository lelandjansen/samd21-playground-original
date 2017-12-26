#ifndef PERIPHERAL_GPIO_BUTTON_H_
#define PERIPHERAL_GPIO_BUTTON_H_

namespace peripheral {

class GpioButton {
 public:
  GpioButton() = default;
  virtual ~GpioButton() = default;
  virtual auto IsPressed() const -> bool = 0;
 
 private:
  GpioButton(const GpioButton&) = delete;
  GpioButton& operator=(const GpioButton&) = delete;
};

}  // namespace peripheral

#endif  // PERIPHERAL_GPIO_BUTTON_H_
