cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm-none-eabi)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_CXX_STANDARD 14)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
  message("DEBUG mode")
  set(build_type_flags "-g -Og")
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy-5.0")
else()
  message("RELEASE mode")
  set(build_type_flags "-O3 -Werror")
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy-5.0;-warnings-as-errors=*")
endif()

set(common_flags "\
  -mcpu=cortex-m0 \
  -mthumb \
  ${build_type_flags} \
  -Wall \
  -Wextra \
  -Wpedantic")
set(CMAKE_C_FLAGS "\
  ${common_flags}")
set(CMAKE_CXX_FLAGS "\
  ${common_flags} \
  -specs=nosys.specs \
  -fno-exceptions")

set(link_file "${CMAKE_SOURCE_DIR}/samd21/samd21j18a_flash.ld")
add_definitions(-D__SAMD21J18A__)

project(blink)
add_subdirectory(app)
add_subdirectory(cmsis)
add_subdirectory(peripheral)
add_subdirectory(samd21)
add_subdirectory(util)

