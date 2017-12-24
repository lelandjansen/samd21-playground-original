list(APPEND VENDOR_ATMEL_ASF_SRC_FILES
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils/syscalls/gcc/syscalls.c"
  "src/asf/common/utils/interrupt/interrupt_sam_nvic.c"
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/source/system_samd21.c"
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/source/gcc/startup_samd21.c")
list(APPEND VENDOR_ATMEL_ASF_INCLUDES
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/source"
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils/cmsis/samd21/include"
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils"
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils/preprocessor"
  "src/asf/${ATMEL_GENERAL_FAMILY}/utils/header_files"
  "src/asf/common/utils"
  "src/asf/common/boards"
  "src/asf/common2/boards/user_board")
