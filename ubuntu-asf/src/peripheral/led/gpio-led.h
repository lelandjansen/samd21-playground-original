#ifndef PERIPHERAL_LED_GPIO_LED_H_
#define PERIPHERAL_LED_GPIO_LED_H_

namespace peripheral {

class GpioLed {
 public:
  GpioLed() = default;
  virtual ~GpioLed() = default;
  virtual auto On() const -> void = 0;
  virtual auto Off() const -> void = 0;
  virtual auto Toggle() const -> void = 0;
 private:
  GpioLed(const GpioLed&) = delete;
  GpioLed& operator=(const GpioLed&) = delete;
};

}  // namespace peripheral

#endif  // PERIPHERAL_LED_GPIO_LED_H_
