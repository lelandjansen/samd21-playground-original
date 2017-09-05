#include "clock.h"

#include "util/reset.h"
#include "samd21/samd21j18a.h"
#include "util/wait.h"

namespace util {

namespace {

auto SetNvmFlashWaitState() -> void {
	// Assumes 48 MHz clock and 3.3 V power supply
	NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val;
}

auto EnableDigitalInterfaceClock() -> void {
	PM->APBAMASK.reg |= PM_APBAMASK_GCLK;
}

auto EnableExternalXosc32kClock() -> void {
	// External 32.768 kHz oscillator
	SYSCTRL->XOSC32K.reg = SYSCTRL_XOSC32K_STARTUP(0x6u) | SYSCTRL_XOSC32K_XTALEN | SYSCTRL_XOSC32K_EN32K;
	SYSCTRL->XOSC32K.bit.ENABLE = true;
	WAIT_UNTIL(SYSCTRL->PCLKSR.bit.XOSC32KRDY);
}

auto SetOxck32kAsGclk1Source() -> void {
	GCLK->GENDIV.reg = GCLK_GENDIV_ID(1);
  WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);
	GCLK->GENCTRL.reg = GCLK_GENCTRL_ID(1) | GCLK_GENCTRL_SRC_XOSC32K | GCLK_GENCTRL_GENEN;
	WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);
}

auto SetGclk1AsGclk0MultiplexerSource() -> void {
	GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(0) | GCLK_CLKCTRL_GEN_GCLK1 | GCLK_CLKCTRL_CLKEN;
	WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);
}

auto EnableDfll48mClock() -> void {
	SYSCTRL->DFLLCTRL.reg = SYSCTRL_DFLLCTRL_ENABLE;
  WAIT_UNTIL(SYSCTRL->PCLKSR.bit.DFLLRDY);
	SYSCTRL->DFLLMUL.reg = SYSCTRL_DFLLMUL_CSTEP(31) | SYSCTRL_DFLLMUL_FSTEP(511) | SYSCTRL_DFLLMUL_MUL((kMainClockFrequency / kExternalOscillatorFrequency));
	WAIT_UNTIL(SYSCTRL->PCLKSR.bit.DFLLRDY);
	SYSCTRL->DFLLCTRL.reg |= SYSCTRL_DFLLCTRL_MODE | SYSCTRL_DFLLCTRL_WAITLOCK | SYSCTRL_DFLLCTRL_QLDIS;
	WAIT_UNTIL(SYSCTRL->PCLKSR.bit.DFLLRDY);
	SYSCTRL->DFLLCTRL.reg |= SYSCTRL_DFLLCTRL_ENABLE;
  WAIT_UNTIL(SYSCTRL->PCLKSR.bit.DFLLLCKC && SYSCTRL->PCLKSR.bit.DFLLLCKF);
	WAIT_UNTIL(SYSCTRL->PCLKSR.bit.DFLLRDY);
}

auto SetGclk0GeneratorToDfll48m() -> void {
	GCLK->GENDIV.reg = GCLK_GENDIV_ID(0);
	WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);
	GCLK->GENCTRL.reg = GCLK_GENCTRL_ID(0) | GCLK_GENCTRL_SRC_DFLL48M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN;
	WAIT_WHILE(GCLK->STATUS.bit.SYNCBUSY);
}

}  // namespace

auto ClockInit() -> void {
	SetNvmFlashWaitState();
  EnableDigitalInterfaceClock();
	EnableExternalXosc32kClock();
	SoftwareReset();
	SetOxck32kAsGclk1Source();
	SetGclk1AsGclk0MultiplexerSource();
	EnableDfll48mClock();
	SetGclk0GeneratorToDfll48m();
	// SystemCoreClock = kMainClockFrequency;
}

}  // namespace util
