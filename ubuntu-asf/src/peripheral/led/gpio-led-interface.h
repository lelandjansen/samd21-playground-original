#ifndef PERIPHERAL_LED_GPIO_LED_INTERFACE_H_
#define PERIPHERAL_LED_GPIO_LED_INTERFACE_H_

namespace peripheral {

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

}  // namespace peripheral

#endif  // PERIPHERAL_LED_GPIO_LED_INTERFACE_H_
