list(APPEND VENDOR_ATMEL_ASF_SRC_FILES
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils/syscalls/gcc/syscalls.c"
    "${ASF_ROOT}/common/utils/interrupt/interrupt_sam_nvic.c"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/source/system_samd21.c"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/source/gcc/startup_samd21.c")
list(APPEND VENDOR_ATMEL_ASF_INCLUDES
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/source"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/include"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils/preprocessor"
    "${ASF_ROOT}/${ATMEL_GENERAL_FAMILY}/utils/header_files"
    "${ASF_ROOT}/common/utils"
    "${ASF_ROOT}/common/boards"
    "${ASF_ROOT}/common2/boards/user_board")
