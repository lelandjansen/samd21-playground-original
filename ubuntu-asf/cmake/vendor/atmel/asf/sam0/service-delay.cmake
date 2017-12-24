


if(DEFINED VENDOR_ATMEL_ASF_SERVICE_DELAY_OPT_MODE)
    if(VENDOR_ATMEL_ASF_SERVICE_DELAY_OPT_MODE STREQUAL "SYSTICK")
        add_definitions(-DSYSTICK_MODE)

        list (APPEND VENDOR_ATMEL_ASF_SRC_FILES
                "src/ASF/common2/services/delay/${ATMEL_GENERAL_FAMILY}/systick_counter.c"
                )
    elseif(VENDOR_ATMEL_ASF_SERVICE_DELAY_OPT_MODE STREQUAL "CYCLE")
        add_definitions(-DCYCLE_MODE)

        list (APPEND VENDOR_ATMEL_ASF_SRC_FILES
                "src/ASF/common2/services/delay/${ATMEL_GENERAL_FAMILY}/cycle_counter.c"
                )
    else()
        message(SEND_ERROR "VENDOR_ATMEL_ASF_SERVICE_DELAY_OPT_MODE CAN ONLY BE SYSTICK OR CYCLE")
    endif()
else()
    message(SEND_ERROR "VENDOR_ATMEL_ASF_SERVICE_DELAY_OPT_MODE MUST BE SET")
endif()


list (APPEND VENDOR_ATMEL_ASF_INCLUDES
        "src/ASF/common2/services/delay"
        )
