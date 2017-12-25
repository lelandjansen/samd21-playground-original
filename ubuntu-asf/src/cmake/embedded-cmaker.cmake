set(TARGET_OUTPUT_NAME ${PROJECT_NAME}.elf)

# Ensure CPU_TYPE is lowercase to avoid case sensitivity issues in Linux vs
# Windows
string(TOLOWER ${CPU_TYPE} ${CPU_TYPE})

if(CPU_TYPE STREQUAL "atsamc21j18a" OR CPU_TYPE STREQUAL "atsamc21j17a")
  set(CPU_MCPU "cortex-m0plus")
  set(CPU_FAMILY "SAMC21")
  set(CPU_VENDOR "atmel")
elseif(CPU_TYPE STREQUAL "atsamd21j18a" OR CPU_TYPE STREQUAL "atsamd21j17a" 
    OR CPU_TYPE STREQUAL "atsamd21g16a")
  set(CPU_MCPU "cortex-m0plus")
  set(CPU_FAMILY "SAMD21")
  set(CPU_VENDOR "atmel")
elseif(CPU_TYPE STREQUAL "atsame70q20")
    set(CPU_MCPU "m7")
else()
    message(FATAL_ERROR "Unknown cpu type ${CPU_TYPE}")
endif()

message("CPU Vendor: ${CPU_VENDOR}")
message("CPU Family: ${CPU_FAMILY}")
message("CPU Type: ${CPU_MCPU}")

set(VENDOR_SRC_FILES "")
set(VENDOR_INCLUDES "")
set(VENDOR_LIBS "")

set(_INCLUDED_FILE 0)
include(vendor/${CPU_VENDOR}/vendor OPTIONAL RESULT_VARIABLE _INCLUDED_FILE)
if (_INCLUDED_FILE)
  message("CPU Vendor Specific configuration loaded")
endif()

set(_INCLUDED_FILE 0)
include(vendor/${CPU_VENDOR}/${CPU_TYPE}
  OPTIONAL RESULT_VARIABLE _INCLUDED_FILE)
if (_INCLUDED_FILE)
  message("CPU CMake Specific configuration loaded")
endif()

set(COMMON_FLAGS "\
    -mcpu=${CPU_MCPU} \
    -Wall \
    -Wextra \
    -Wpedantic")
set(CMAKE_C_FLAGS "\
    ${CMAKE_CXX_FLAGS} \
    ${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "\
    ${CMAKE_CXX_FLAGS} \
    ${COMMON_FLAGS} \
    -fno-exceptions")
set(CMAKE_EXE_LINKER_FLAGS "\
    ${CMAKE_EXE_LINKER_FLAGS} \
    -T ${LINKER_SCRIPT}")
