#include "led-green.h"

#include <cassert>

#include "sam.h"
#include "../../util/wait.h"

namespace perhipial {
  
namespace {
  
// For PA11:
// TCC0
// WO[3]
// CC3
// Perhaps PIN_PA11F_TCC0_WO3

void setup() {
  REG_GCLK_GENDIV = GCLK_GENDIV_DIV(1) |          // Divide the 48MHz clock source by divisor 1: 48MHz/1=48MHz
                    GCLK_GENDIV_ID(4);            // Select Generic Clock (GCLK) 4
  //GCLK->GENDIV.reg = GCLK_GENDIV_DIV(1) | GCLK_GENDIV_ID(4);
  WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);
  //
  //GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(4) | GCLK_GENCTRL_SRC_DFLL48M/*GCLK_CLKCTRL_GEN_GCLK0*/ | GCLK_CLKCTRL_CLKEN;
	//WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);

  REG_GCLK_GENCTRL = GCLK_GENCTRL_IDC |           // Set the duty cycle to 50/50 HIGH/LOW
                     GCLK_GENCTRL_GENEN |         // Enable GCLK4
                     GCLK_GENCTRL_SRC_DFLL48M |   // Set the 48MHz clock source
                     GCLK_GENCTRL_ID(4);          // Select GCLK4
  WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);

  // Do not setup GPIO and instead us a yet to be defined perhipial type
  // Enable port multiplexer
  PORT->Group[0].PINCFG[PIN_PA11].bit.PMUXEN = 1;
  WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);
 ////
  //////// Connect the TCC0 timer to digital output D7 - port pins are paired odd PMUO and even PMUXE
  //////// F & E specify the timers: TCC0, TCC1 and TCC2
  //PORT->Group[0].PMUX[PIN_PA11 / 2].reg = PORT_PMUX_PMUXO_F | PORT_PMUX_PMUXE_F;
  //
  //PORT->Group[0].PMUX[PIN_PA11 / 2].bit.PMUXO = 4;
  
  //PORT->Group[0].PINCFG[PIN_PA11].reg |= PORT_PINCFG_PMUXEN;
  //PORT->Group[0].PMUX[PIN_PA11 / 2].bit.PMUXO = 4;
  
  //PORT->Group[0].PMUX[PIN_PA11 >> 1].bit.PMUXO = PORT_PMUX_PMUXO_F_Val;
  
  PORT->Group[0].PMUX[PIN_PA11 >> 1].reg |= PORT_PMUX_PMUXO_F;
  WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);

  // Feed GCLK4 to TCC0 and TCC1
  REG_GCLK_CLKCTRL = GCLK_CLKCTRL_CLKEN |         // Enable GCLK4 to TCC0 and TCC1
                     GCLK_CLKCTRL_GEN_GCLK4 |     // Select GCLK4
                     GCLK_CLKCTRL_ID_TCC0_TCC1;   // Feed GCLK4 to TCC0 and TCC1
  WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);

  //// Dual slope PWM operation: timers continuously count up to PER register value then down 0
  //REG_TCC0_WAVE |= TCC_WAVE_POL(0xF) |         // Reverse the output polarity on all TCC0 outputs
                   //TCC_WAVE_WAVEGEN_DSBOTTOM;    // Setup dual slope PWM on TCC0
  //while (TCC0->SYNCBUSY.bit.WAVE);               // Wait for synchronization
////
  //Set for Single slope PWM operation: timers or counters count up to TOP value and then repeat
  REG_TCC0_WAVE |= TCC_WAVE_WAVEGEN_NPWM;       // Reverse the output polarity on all TCC0 outputs
  WAIT_WHILE(TCC0->SYNCBUSY.bit.WAVE);               // Wait for synchronization

  // Each timer counts up to a maximum or TOP value set by the PER register,
  // this determines the frequency of the PWM operation:
  REG_TCC0_PER = 255;         // Set the frequency of the PWM on TCC0
  WAIT_WHILE(TCC0->SYNCBUSY.bit.PER);
 
  // Set the PWM signal to output 50% duty cycle
  REG_TCC0_CC3 = 255 / 2;         // TCC0 CC3 - on D7
  WAIT_WHILE(TCC0->SYNCBUSY.bit.CC1);
 
  // Divide the 48MHz signal by 1 giving 48MHz (20.83ns) TCC0 timer tick and enable the outputs
  REG_TCC0_CTRLA |= TCC_CTRLA_PRESCALER_DIV1 |    // Divide GCLK4 by 1
                    TCC_CTRLA_ENABLE;             // Enable the TCC0 output
  WAIT_WHILE(TCC0->SYNCBUSY.bit.ENABLE);
}


//
//void setup()
//{
  //REG_GCLK_GENDIV = GCLK_GENDIV_DIV(3) |          // Divide the 48MHz clock source by divisor 3: 48MHz/3=16MHz
                    //GCLK_GENDIV_ID(4);            // Select Generic Clock (GCLK) 4
  //while (GCLK->STATUS.bit.SYNCBUSY);              // Wait for synchronization
 //
  //REG_GCLK_GENCTRL = GCLK_GENCTRL_IDC |           // Set the duty cycle to 50/50 HIGH/LOW
                     //GCLK_GENCTRL_GENEN |         // Enable GCLK4
                     //GCLK_GENCTRL_SRC_DFLL48M |   // Set the 48MHz clock source
                     //GCLK_GENCTRL_ID(4);          // Select GCLK4
  //while (GCLK->STATUS.bit.SYNCBUSY);              // Wait for synchronization
 //
  //PORT->Group[0].PINCFG[PIN_PA20].bit.PMUXEN = 1;
  //
  //// Connect the TCC0 timer to the port outputs - port pins are paired odd PMUO and even PMUXE
  //// F & E specify the timers: TCC0, TCC1 and TCC2
  //PORT->Group[0].PMUX[PIN_PA20 >> 1].reg = PORT_PMUX_PMUXO_F | PORT_PMUX_PMUXE_F;
  ////PORT->Group[g_APinDescription[6].ulPort].PMUX[g_APinDescription[6].ulPin >> 1].reg = PORT_PMUX_PMUXO_F | PORT_PMUX_PMUXE_F;
 //
  //// Feed GCLK4 to TCC0 and TCC1
  //REG_GCLK_CLKCTRL = GCLK_CLKCTRL_CLKEN |         // Enable GCLK4 to TCC0 and TCC1
                     //GCLK_CLKCTRL_GEN_GCLK4 |     // Select GCLK4
                     //GCLK_CLKCTRL_ID_TCC0_TCC1;   // Feed GCLK4 to TCC0 and TCC1
  //while (GCLK->STATUS.bit.SYNCBUSY);              // Wait for synchronization
 //
  //// Dual slope PWM operation: timers continuously count up to PER register value then down 0
  //REG_TCC0_WAVE |= TCC_WAVE_POL(0xF) |         // Reverse the output polarity on all TCC0 outputs
                   //TCC_WAVE_WAVEGEN_DSBOTTOM;    // Setup dual slope PWM on TCC0
  //while (TCC0->SYNCBUSY.bit.WAVE);               // Wait for synchronization
 //
  //// Each timer counts up to a maximum or TOP value set by the PER register,
  //// this determines the frequency of the PWM operation:
  //// 400 = 20kHz; 800= 10 kHz; 4000 = 2 kHz
  //REG_TCC0_PER = 4000;      // Set the frequency of the PWM on TCC0 to X khz
  //while(TCC0->SYNCBUSY.bit.PER);
 //
  //// The CCBx register value corresponds to the pulsewidth in microseconds (us)
  //REG_TCC0_CCB0 = 200;       // TCC0 CCB0 - 50% duty cycle on D2
  //while(TCC0->SYNCBUSY.bit.CCB0);
  //REG_TCC0_CCB1 = 200;       // TCC0 CCB1 - 50% duty cycle on D5
  //while(TCC0->SYNCBUSY.bit.CCB1);
  //REG_TCC0_CCB2 = 200;       // TCC0 CCB2 - 50% duty cycle on D6
  //while(TCC0->SYNCBUSY.bit.CCB2);
  //REG_TCC0_CCB3 = 200;       // TCC0 CCB3 - 50% duty cycle on D7
  //while(TCC0->SYNCBUSY.bit.CCB3);
 //
  //// Divide the 16MHz signal by 1 giving 16MHz (62.5ns) TCC0 timer tick and enable the outputs
  //REG_TCC0_CTRLA |= TCC_CTRLA_PRESCALER_DIV1 |    // Divide GCLK4 by 1
                    //TCC_CTRLA_ENABLE;             // Enable the TCC0 output
  //while (TCC0->SYNCBUSY.bit.ENABLE);              // Wait for synchronization
//}


  
}  // namespace

bool LedGreen::instantiated_ = false;

LedGreen::LedGreen() {
  assert(!instantiated_);
  instantiated_ = true;
  //SetAsOutput();
  setup();
  //SetupClock();
  //SetupPwm();
  //Off();
}

LedGreen::~LedGreen() {
  Off();
  instantiated_ = false;
}

auto LedGreen::SetDutyCycle(uint8_t duty_cycle) const -> void {
    //// Set the PWM signal to output 50% duty cycle initially (0.5 x 255)
  //REG_TCC1_CC1 = duty_cycle;        
  //while (TCC1->SYNCBUSY.bit.CC1);                // Wait for synchronization
}

auto LedGreen::Off() const -> void {
  //SetDutyCycle(0);
}

auto LedGreen::SetAsOutput() const -> void {
  PORT->Group[0].DIRSET.reg = PORT_PA11;
}

}  // namespace perhipial
