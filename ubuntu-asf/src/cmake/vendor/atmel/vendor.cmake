# Assume all CPU_TYPEs have AT prefix for what we do here
string(TOUPPER ${CPU_TYPE} _AT_CPU_TYPE_UPPER)
add_definitions(-D__${_AT_CPU_TYPE_UPPER}__)

string(REGEX REPLACE "^AT" "" _NONAT_CPU_TYPE_UPPER ${_AT_CPU_TYPE_UPPER})
add_definitions(-D__${_NONAT_CPU_TYPE_UPPER}__)

set(ATMEL_GENERAL_FAMILY "")
if(CPU_FAMILY STREQUAL "SAMC21" OR CPU_FAMILY STREQUAL "SAMD21")
  set(ATMEL_GENERAL_FAMILY "sam0")
else()
  message(FATAL_ERROR "Unknown atmel cpu family")
endif()

if(VENDOR_ATMEL_USE_ASF)
  include(vendor/atmel/asf/asf)
endif()

set(CMAKE_EXE_LINKER_FLAGS "\
    -Wl,-gc-sections \
    -Wl,--entry=Reset_Handler \
    -mthumb")
