
list (APPEND VENDOR_ATMEL_ASF_SRC_FILES
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/system.c"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/pinmux/pinmux.c"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt/system_interrupt.c"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21/clock.c"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21/gclk.c"
        )

list (APPEND VENDOR_ATMEL_ASF_INCLUDES
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/reset"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/reset/reset_sam_d_r"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/power/power_sam_d_r"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/interrupt/system_interrupt_samd21"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/pinmux"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/clock"
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/system/clock/clock_samd21_r21"
        )
