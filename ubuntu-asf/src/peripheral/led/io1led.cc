// Resources
// http://asf.atmel.com/docs/3.1.3/sam.drivers.adc.adc_example.sam4s_ek/html/sam_pwm_quickstart.html
// http://asf.atmel.com/docs/3.1.3/sam.drivers.adc.adc_example.sam4s_ek/html/pwm_use_case_1.html


#include "peripheral/led/io1led.h"

#include <cassert>

#include "asf/asf.h"

namespace peripheral {

bool Io1Led::instantiated_ = false;

Io1Led::Io1Led() {
  assert(!instantiated_);  // NOLINT
  instantiated_ = true;
  SetAsPwmOutput();
  Off();
}

Io1Led::~Io1Led() {
  Off();
  instantiated_ = false;
}

auto Io1Led::On() const -> void {
  SetBrightness(UINT8_MAX);
}

auto Io1Led::Off() const -> void {
  SetBrightness(0);
}

auto Io1Led::SetBrightness(__attribute__ ((unused)) const uint8_t level) const -> void {

}

auto Io1Led::SetAsPwmOutput() const -> void {
  pwm_channel_t pwm_channel_instance;
  pmc_enable_periph_clk(ID_PWM);
  pwm_channel_disable(PWM, PWM_CHANNEL_0);
  pwm_clock_t clock_setting = {
        .ul_clka = 1000 * 100,
            .ul_clkb = 0,
                .ul_mck = 48000000
  };
  pwm_init(PWM, &clock_setting);
  pwm_channel_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
  pwm_channel_instance.ul_period = 100;
  pwm_channel_instance.ul_duty = 50;
  pwm_channel_instance.channel = PWM_CHANNEL_0;
  pwm_channel_init(PWM, &pwm_channel_instance);
  
  pwm_channel_enable(PWM, PWM_CHANNEL_0);
}

}  // namespace peripheral
