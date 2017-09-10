cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm-none-eabi)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_C_FLAGS "\
  -Wl,--start-group \
  -lgcc \
  -lc \
  -lm \
  -lrdimon \
  -Wl,--end-group")
set(link_file "${CMAKE_SOURCE_DIR}/samd21j18a_flash.ld")
add_definitions(-D__SAMD21J18A__)

project(omzlo-cmake C)
add_executable(omzlo-cmake
  main.c
  startup_samd21.c
  system_samd21.c
  )
target_include_directories(omzlo-cmake PRIVATE
  include
  cmsis
  .)
set_target_properties(omzlo-cmake PROPERTIES
  OUTPUT_NAME "omzlo-cmake.elf"
  LINK_FLAGS "\
    -T${link_file} \
    -mthumb \
    -mcpu=cortex-m0 \
    -Wl,--gc-sections"
  LINK_DEPENDS ${link_file})

