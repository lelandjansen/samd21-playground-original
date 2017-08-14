#include "interrupts.h"

#include <stdbool.h>

#include "sam.h"
#include "util/wait.h"

//void SetupClock(void) {
		//// To run at 48MHz you will need to set the flash wait states according to Table 37-39. (Maximum Operating Frequency):
		//NVMCTRL->CTRLB.bit.RWS = 1;			// Set Flash Wait States to 1 for 3.3V operation
		//
		//// Then allow for an errata in accessing the DFLL register:
		//SYSCTRL->DFLLCTRL.reg = 0;			// See Errata 9905
		//while ((SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_DFLLRDY) == 0);	// Wait for DFLL synchronization complete
		//
		////// Then set the DFLL calibration register and configure the DFLL:
		////int coarse = NVM_READ_CAL (NVM_DFLL48M_COARSE_CAL);	// Load DFLL calibration from "NVM Software Calibration Row"
		////int fine = NVM_READ_CAL (NVM_DFLL48M_FINE_CAL);
		//// DFLL default is open loop mode:
		//SYSCTRL->DFLLMUL.reg = SYSCTRL_DFLLMUL_MUL (48000);		// Set to multiply USB SOF frequency (when USB attached)
		//SYSCTRL->DFLLVAL.reg = SYSCTRL_DFLLVAL_COARSE (CONF_CLOCK_DFLL_MAX_COARSE_STEP_SIZE) | SYSCTRL_DFLLVAL_FINE (CONF_CLOCK_DFLL_MAX_FINE_STEP_SIZE);	// Set calibration (for when no USB)
		//// Set DFLL for USB Clock Recovery Mode, Bypass Coarse Lock, Disable Chill Cycle,
		////   Fine calibration register locks (stable) after fine lock
		//SYSCTRL->DFLLCTRL.reg = SYSCTRL_DFLLCTRL_ENABLE | SYSCTRL_DFLLCTRL_USBCRM | SYSCTRL_DFLLCTRL_BPLCKC | SYSCTRL_DFLLCTRL_CCDIS | SYSCTRL_DFLLCTRL_STABLE;
		//while ((SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_DFLLRDY) == 0);	// Wait for DFLL synchronization complete
		//
		//// Setup Generic Clock Generator 0 with DFLL48M as source:
		//GCLK->GENDIV.reg = GCLK_GENDIV_ID (0) | GCLK_GENDIV_DIV (1);
		//GCLK->GENCTRL.reg = GCLK_GENCTRL_ID (0) | GCLK_GENCTRL_SRC (GCLK_SOURCE_DFLL48M) | GCLK_GENCTRL_RUNSTDBY | GCLK_GENCTRL_GENEN;
		//while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY);	// Wait till synchronization is complete
//}

//void SetupClock(void) {
	//// Reference: https://github.com/arduino/ArduinoCore-samd/blob/master/cores/arduino/startup.c
	///* Set 1 Flash Wait State for 48MHz, cf tables 20.9 and 35.27 in SAMD21 Datasheet */
	//NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val;
	//
	///* ----------------------------------------------------------------------------------------------
	//* 1) Enable XOSC32K clock (External on-board 32.768Hz oscillator)
	//*/
	//SYSCTRL->XOSC32K.reg = SYSCTRL_XOSC32K_STARTUP( 0x6u ) | /* cf table 15.10 of product datasheet in chapter 15.8.6 */
                           //SYSCTRL_XOSC32K_XTALEN | SYSCTRL_XOSC32K_EN32K ;
	//SYSCTRL->XOSC32K.bit.ENABLE = 1 ; /* separate call, as described in chapter 15.6.3 */
	//while ((SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_XOSC32KRDY) == 0)
//}

// Clock setup resource:
// http://community.atmel.com/forum/samd21-xplained-pro-operating-frequency

//// 8 MHZ
//void SetupClock(void) {
//// To just set the main clock to 8MHz you can configure the OSC8M prescaler to divide by 1
//SYSCTRL->OSC8M.bit.PRESC = 0;		// Set OSC8M prescaler to 1
//}

void EnableExternalInterrupts(void) {
	NVIC_EnableIRQ(TC3_IRQn);
}

void DisableExternalInterrupts(void) {
	NVIC_DisableIRQ(TC3_IRQn);
}

void InitTC3(void) {
	/* Configure Timer/Counter 3 as a timer to blink LED0 */
	// Configure Clocks
	REG_GCLK_CLKCTRL = GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN_GCLK0 | GCLK_CLKCTRL_ID_TCC2_TC3;
	REG_PM_APBCMASK |= PM_APBCMASK_TC3; // Enable TC3 bus clock
	
	// Configure TC3 (16 bit counter by default)
	REG_TC3_CTRLA |= TC_CTRLA_PRESCALER_DIV256;
	
	// Enable interrupts
	REG_TC3_INTENSET = TC_INTENSET_OVF | TC_INTENSET_ERR;
	
	// Enable TC3
	REG_TC3_CTRLA |= TC_CTRLA_ENABLE;
	while(TC3->COUNT16.STATUS.bit.SYNCBUSY);  // wait for TC3 to be enabled
}

void TC3_Handler(void) {
	// Overflow interrupt triggered
	if (TC3->COUNT16.INTFLAG.bit.OVF) {
	 	PORT->Group[1].OUTTGL.reg = PORT_PB30;
		PORT->Group[0].OUTTGL.reg = PORT_PA13;
		REG_TC3_INTFLAG = TC_INTFLAG_OVF;
	}
	
	// Error interrupt triggered
	else if (TC3->COUNT16.INTFLAG.bit.ERR) {
		//TC3_error = 1;
		REG_TC3_INTFLAG = TC_INTFLAG_ERR;
	}
}
