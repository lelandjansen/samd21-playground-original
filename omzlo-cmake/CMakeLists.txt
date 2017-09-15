cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm-none-eabi)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "\
  -mcpu=cortex-m0 \
  -mthumb \
  -g \
  -Wl,--start-group \
  -lgcc \
  -lc \
  -lm \
  -lrdimon \
  -Wl,--end-group")
set(CMAKE_CXX_FLAGS "\
  --specs=nosys.specs \
  -mcpu=cortex-m0 \
  -mthumb \
  -g \
  -lc \
  -lm \
  -lrdimon \
  -Wall \
  -Wextra \
  -Wpedantic \
  -fno-exceptions")
set(link_file "${CMAKE_SOURCE_DIR}/samd21/samd21j18a_flash.ld")
add_definitions(-D__SAMD21J18A__)

project(omzlo-cmake)
add_subdirectory(app)
add_subdirectory(cmsis)
add_subdirectory(samd21)
add_subdirectory(led)
add_subdirectory(util)

