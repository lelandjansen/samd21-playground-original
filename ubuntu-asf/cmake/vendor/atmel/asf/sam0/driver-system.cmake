list(APPEND VENDOR_ATMEL_ASF_SRC_FILES
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/system.c"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/pinmux/pinmux.c"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt/system_interrupt.c"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21_da_ha1/clock.c"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.c")
list(APPEND VENDOR_ATMEL_ASF_INCLUDES
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/reset"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/reset/reset_sam_d_r_h"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/power/power_sam_d_r_h"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt/system_interrupt_samd21"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/pinmux"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/clock"
  "src/asf/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21_da_ha1")
