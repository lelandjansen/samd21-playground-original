set(VENDOR_ATMEL_ASF_SRC_FILES "")
set(VENDOR_ATMEL_ASF_INCLUDES "")

include(vendor/atmel/asf/sam0/base)

if (VENDOR_ATMEL_ASF_DRIVER_PORT)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/driver-port)
endif()
if (VENDOR_ATMEL_ASF_DRIVER_SYSTEM)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/driver-system)
endif()
if (VENDOR_ATMEL_ASF_DRIVER_EXTINT)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/driver-extint)
endif()
if (VENDOR_ATMEL_ASF_DRIVER_TC)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/driver-tc)
endif()
if (VENDOR_ATMEL_ASF_DRIVER_WDT)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/driver-wdt)
endif()
if (VENDOR_ATMEL_ASF_DRIVER_NVM)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/driver-nvm)
endif()
if (VENDOR_ATMEL_ASF_SERVICE_IOPORT)
  include(vendor/atmel/asf/service-ioport)
endif()
if (VENDOR_ATMEL_ASF_SERVICE_SLEEPMGR)
  include(vendor/atmel/asf/service-sleepmgr)
endif()
if (VENDOR_ATMEL_ASF_SERVICE_DELAY)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/service-delay)
endif()
if (VENDOR_ATMEL_ASF_SERVICE_EEPROM)
  include(vendor/atmel/asf/${ATMEL_GENERAL_FAMILY}/service-eeprom)
endif()

list(APPEND VENDOR_ATMEL_ASF_INCLUDES
    "${ASF_ROOT}/thirdparty/Lib/GCC"
    "${ASF_ROOT}/thirdparty/CMSIS/Include"
    "${CMAKE_SOURCE_DIR}/config")

include_directories(${VENDOR_ATMEL_ASF_INCLUDES})

add_library(vendor_lib_atmel_asf
    ${VENDOR_ATMEL_ASF_SRC_FILES})

set(_ASF_LIBARM_MATH "")
if (${ATMEL_GENERAL_FAMILY} STREQUAL "sam0")
  set(_ASF_LIBARM_MATH "libarm_cortexM0l_math.a")
else()
  message(FATAL_ERROR "Unknown general family to determine libarm math")
endif()

add_definitions(-DARM_MATH_CM0=true)
list(APPEND VENDOR_LIBS
    vendor_lib_atmel_asf
    "${ASF_ROOT}/thirdparty/CMSIS/Lib/GCC/${_ASF_LIBARM_MATH}")
