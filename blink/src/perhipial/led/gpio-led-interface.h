#ifndef PERHIPIAL_LED_GPIO_LED_INTERFACE_H_
#define PERHIPIAL_LED_GPIO_LED_INTERFACE_H_

namespace perhipial {

class GpioLedInterface {
 public:
  GpioLedInterface() = default;
  virtual ~GpioLedInterface() = default;
  virtual auto On() const -> void = 0;
  virtual auto Off() const -> void = 0;
  virtual auto Toggle() const -> void = 0;
 private:
  GpioLedInterface(const GpioLedInterface&) = delete;
  GpioLedInterface& operator=(const GpioLedInterface&) = delete;
};

}  // namespace perhipial

#endif  // PERHIPIAL_LED_GPIO_LED_INTERFACE_H_

