
if(VENDOR_ATMEL_USE_ASF)
    set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/src/ASF/sam0/utils/linker_scripts/samd21/gcc/samd21e16a_flash.ld)
endif()