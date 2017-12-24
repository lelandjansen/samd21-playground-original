

list (APPEND VENDOR_ATMEL_ASF_SRC_FILES
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/extint/extint_sam_d_r/extint.c"
        )

list (APPEND VENDOR_ATMEL_ASF_INCLUDES
        "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/extint"
        )

if(DEFINED VENDOR_ATMEL_ASF_DRIVER_EXTINT_OPT_CALLBACK)
    if(VENDOR_ATMEL_ASF_DRIVER_EXTINT_OPT_CALLBACK)
        add_definitions(-DEXTINT_CALLBACK_MODE=true)

        list (APPEND VENDOR_ATMEL_ASF_SRC_FILES
                "src/ASF/${ATMEL_GENERAL_FAMILY}/drivers/extint/extint_callback.c"
                )
    else()
        add_definitions(-DEXTINT_CALLBACK_MODE=false)
    endif()
else()
    message(SEND_ERROR "VENDOR_ATMEL_ASF_DRIVER_EXTINT_OPT_CALLBACK MUST BE SET")
endif()