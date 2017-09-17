// Copyright (c) 2016 Atmel Corporation. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. The name of Atmel may not be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// 4. This software may only be redistributed and used in connection with an
//    Atmel microcontroller product.
//
// THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
// EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include <stddef.h>
#include <stdint.h>

#include "samd21.h"
#include "segments.h"
#include "interrupt-handlers.h"

#define RESERVED NULL

__attribute__ ((section(".vectors")))
const DeviceVectors exception_table = {
  // Configure Initial Stack Pointer, using linker-generated symbols
  .pvStack            = &_estack,

  .pfnReset_Handler   = Reset_Handler,
  .pfnNMI_Handler     = NMI_Handler,
  .pfnHardFault_Handler = HardFault_Handler,
  .pvReservedM12      = RESERVED, 
  .pvReservedM11      = RESERVED, 
  .pvReservedM10      = RESERVED, 
  .pvReservedM9       = RESERVED, 
  .pvReservedM8       = RESERVED, 
  .pvReservedM7       = RESERVED, 
  .pvReservedM6       = RESERVED, 
  .pfnSVC_Handler     = SVC_Handler,
  .pvReservedM4       = RESERVED, 
  .pvReservedM3       = RESERVED, 
  .pfnPendSV_Handler  = PendSV_Handler,
  .pfnSysTick_Handler = SysTick_Handler,

  // Configurable interrupts
  .pfnPM_Handler      = PM_Handler,      //  0 Power Manage
  .pfnSYSCTRL_Handler = SYSCTRL_Handler, //  1 System Contro
  .pfnWDT_Handler     = WDT_Handler,     //  2 Watchdog Timer
  .pfnRTC_Handler     = RTC_Handler,     //  3 Real-Time Counter
  .pfnEIC_Handler     = EIC_Handler,     //  4 External Interrupt Controller
  .pfnNVMCTRL_Handler = NVMCTRL_Handler, //  5 Non-Volatile Memory Controller
  .pfnDMAC_Handler    = DMAC_Handler,    //  6 Direct Memory Access Controller
#ifdef ID_USB
  .pfnUSB_Handler     = USB_Handler,     //  7 Universal Serial Bus
#else
  .pvReserved7        = RESERVED,        //  7 Reserved
#endif
  .pfnEVSYS_Handler   = EVSYS_Handler,   //  8 Event System Interface
  .pfnSERCOM0_Handler = SERCOM0_Handler, //  9 Serial Communication Interface 0
  .pfnSERCOM1_Handler = SERCOM1_Handler, // 10 Serial Communication Interface 1
  .pfnSERCOM2_Handler = SERCOM2_Handler, // 11 Serial Communication Interface 2
  .pfnSERCOM3_Handler = SERCOM3_Handler, // 12 Serial Communication Interface 3
#ifdef ID_SERCOM4
  .pfnSERCOM4_Handler = SERCOM4_Handler, // 13 Serial Communication Interface 4
#else
  .pvReserved13       = RESERVED,        // 13 Reserved
#endif
#ifdef ID_SERCOM5
  .pfnSERCOM5_Handler = SERCOM5_Handler, // 14 Serial Communication Interface 5
#else
  .pvReserved14       = RESERVED,        // 14 Reserved
#endif
  .pfnTCC0_Handler    = TCC0_Handler,    // 15 Timer Counter Control 0
  .pfnTCC1_Handler    = TCC1_Handler,    // 16 Timer Counter Control 1
  .pfnTCC2_Handler    = TCC2_Handler,    // 17 Timer Counter Control 2
  .pfnTC3_Handler     = TC3_Handler,     // 18 Basic Timer Counter 0
  .pfnTC4_Handler     = TC4_Handler,     // 19 Basic Timer Counter 1
  .pfnTC5_Handler     = TC5_Handler,     // 20 Basic Timer Counter 2
#ifdef ID_TC6
  .pfnTC6_Handler     = TC6_Handler,     // 21 Basic Timer Counter 3
#else
  .pvReserved21       = RESERVED,        // 21 Reserved
#endif
#ifdef ID_TC7
  .pfnTC7_Handler     = TC7_Handler,     // 22 Basic Timer Counter 4
#else
  .pvReserved22       = RESERVED,        // 22 Reserved
#endif
#ifdef ID_ADC
  .pfnADC_Handler     = ADC_Handler,     // 23 Analog Digital Converter
#else
  .pvReserved23       = RESERVED,        // 23 Reserved
#endif
#ifdef ID_AC
  .pfnAC_Handler      = AC_Handler,      // 24 Analog Comparators 0
#else
  .pvReserved24       = RESERVED,        // 24 Reserved
#endif
#ifdef ID_DAC
  .pfnDAC_Handler     = DAC_Handler,     // 25 Digital Analog Converter
#else
  .pvReserved25       = RESERVED,        // 25 Reserved
#endif
#ifdef ID_PTC
  .pfnPTC_Handler     = PTC_Handler,     // 26 Peripheral Touch Controller
#else
  .pvReserved26       = RESERVED,        // 26 Reserved
#endif
#ifdef ID_I2S
  .pfnI2S_Handler     = I2S_Handler,     // 27 Inter-IC Sound Interface
#else
  .pvReserved27       = RESERVED,        // 27 Reserved
#endif
#ifdef ID_AC1
  .pfnAC1_Handler     = AC1_Handler      // 28 Analog Comparators 1
#else
  .pvReserved28       = RESERVED         // 28 Reserved
#endif
};

