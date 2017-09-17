#ifndef SAMD21_INTERRUPT_HANDLERS_H_
#define SAMD21_INTERRUPT_HANDLERS_H_

// Default interrupt handler for unused IRQs.
void Default_Handler(void);

// Called on processor reset to initialize device and call main()
void Reset_Handler(void);

// Cortex-M0+ core handlers
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

// Peripheral handlers
void PM_Handler(void);
void SYSCTRL_Handler(void);
void WDT_Handler(void);
void RTC_Handler(void);
void EIC_Handler(void);
void NVMCTRL_Handler(void);
void DMAC_Handler(void);
void USB_Handler(void);
void EVSYS_Handler(void);
void SERCOM0_Handler(void);
void SERCOM1_Handler(void);
void SERCOM2_Handler(void);
void SERCOM3_Handler(void);
void SERCOM4_Handler(void);
void SERCOM5_Handler(void);
void TCC0_Handler(void);
void TCC1_Handler(void);
void TCC2_Handler(void);
void TC3_Handler(void);
void TC4_Handler(void);
void TC5_Handler(void);
void TC6_Handler(void);
void TC7_Handler(void);
void ADC_Handler(void);
void AC_Handler(void);
void DAC_Handler(void);
void PTC_Handler(void);
void I2S_Handler(void);
#ifdef ID_AC1
void AC1_Handler(void);
#endif

#endif  // SAMD21_INTERRUPT_HANDLERS_H_

