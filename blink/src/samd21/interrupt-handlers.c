#include "interrupt-handlers.h"

#include <stdbool.h>
#include <stdint.h>

#include "samd21.h"
#include "segments.h"

int main(void);

void __libc_init_array(void);

void Default_Handler(void) {
  for(;;);
}

// Called on processor reset to initialize the device, and call main()
void Reset_Handler(void) {
  uint32_t *pSrc, *pDest;

  // Initialize the relocate segment
  pSrc = &_etext;
  pDest = &_srelocate;

  if (pSrc != pDest) {
    for (; pDest < &_erelocate;) {
      *pDest++ = *pSrc++;
    }
  }

  // Clear the zero segment
  for (pDest = &_szero; pDest < &_ezero;) {
    *pDest++ = 0;
  }

  // Set the vector table base address
  pSrc = (uint32_t *) & _sfixed;
  SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);

  // Change default QOS values to have the best performance and correct USB
  // behavior
  SBMATRIX->SFR[SBMATRIX_SLAVE_HMCRAMC0].reg = 2;
#if defined(ID_USB)
  USB->DEVICE.QOSCTRL.bit.CQOS = 2;
  USB->DEVICE.QOSCTRL.bit.DQOS = 2;
#endif
  DMAC->QOSCTRL.bit.DQOS = 2;
  DMAC->QOSCTRL.bit.FQOS = 2;
  DMAC->QOSCTRL.bit.WRBQOS = 2;

  // Overwrite the default value of the NVMCTRL.CTRLB.MANW bit 
  // (errata reference 13134)
  NVMCTRL->CTRLB.bit.MANW = 1;

  __libc_init_array();
  main();
  while (true);
}

// Cortex-M0+ core handlers
void NMI_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)   __attribute__((weak, alias("Default_Handler")));

// Peripheral handlers
void PM_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void SYSCTRL_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void WDT_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void RTC_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void EIC_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void NVMCTRL_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void DMAC_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void USB_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void EVSYS_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void SERCOM0_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SERCOM1_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SERCOM2_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SERCOM3_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SERCOM4_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SERCOM5_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void TCC0_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void TCC1_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void TCC2_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void TC3_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void TC4_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void TC5_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void TC6_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void TC7_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void ADC_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void AC_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void DAC_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void PTC_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void I2S_Handler(void)       __attribute__((weak, alias("Default_Handler")));
#ifdef ID_AC1
void AC1_Handler(void)       __attribute__((weak, alias("Default_Handler")));
#endif

