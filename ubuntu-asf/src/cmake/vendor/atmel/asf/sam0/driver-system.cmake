list(APPEND VENDOR_ATMEL_ASF_SRC_FILES
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/system.c"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/pinmux/pinmux.c"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt/system_interrupt.c"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21_da_ha1/clock.c"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.c")
list(APPEND VENDOR_ATMEL_ASF_INCLUDES
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/reset"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/reset/reset_sam_d_r_h"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/power/power_sam_d_r_h"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt/system_interrupt_samd21"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/pinmux"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/clock"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21_da_ha1")
