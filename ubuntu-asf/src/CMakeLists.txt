cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(ASF_ROOT ${CMAKE_SOURCE_DIR}/asf)

find_program(CLANG_TIDY_EXE NAMES
    clang-tidy
    clang-tidy-5.0
    clang-tidy-6.0)
set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")

# Load toolchain definition before the project is declared or it will not work
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(toolchain-gnu-arm)

project(blink)

# embedded-cmaker configuration
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

include_directories(${VENDOR_INCLUDES})
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(app)
add_subdirectory(peripheral)

gcc_generate_map()
