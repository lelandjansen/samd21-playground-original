cmake_minimum_required(VERSION 3.7)

# Load toolchain definition before the project is declared or it will not work
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(toolchain-gnu-arm)

###
# Project Start
###
project(blink)

###
# embedded-cmaker Configuration
###
set(CPU_TYPE atsamd21j18a)
set(VENDOR_ATMEL_USE_ASF TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_SYSTEM TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_EXTINT TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_EXTINT_OPT_CALLBACK TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_PORT TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_TC TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_TC_OPT_ASYNC FALSE)
set(VENDOR_ATMEL_ASF_DRIVER_WDT TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_WDT_OPT_CALLBACKMODE TRUE)
set(VENDOR_ATMEL_ASF_DRIVER_NVM TRUE)
set(VENDOR_ATMEL_ASF_SERVICE_IOPORT TRUE)
set(VENDOR_ATMEL_ASF_SERVICE_DELAY TRUE)
set(VENDOR_ATMEL_ASF_SERVICE_SLEEPMGR TRUE)
set(VENDOR_ATMEL_ASF_SERVICE_EEPROM TRUE)
set(VENDOR_ATMEL_ASF_SERVICE_DELAY_OPT_MODE SYSTICK)
include(embedded-cmaker)

add_definitions(-DBOARD=USER_BOARD)

include_directories(src)

include_directories(${VENDOR_INCLUDES})

add_executable(${TARGET_OUTPUT_NAME}
  src/main.c)
target_link_libraries(${TARGET_OUTPUT_NAME} ${VENDOR_LIBS})

gcc_generate_map()
