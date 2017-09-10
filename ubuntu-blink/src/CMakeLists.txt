cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm-none-eabi)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
#set(CMAKE_LINKER arm-none-eabi-gcc)
set(CMAKE_CXX_STANDARD 14)                                          
set(CMAKE_C_FLAGS "\
  --specs=rdimon.specs \
  -lgcc \
  -lc \
  -lm \
  -lrdimon")
set(CMAKE_CXX_FLAGS "\
  --specs=rdimon.specs \
  -lgcc \
  -lc \
  -lm \
  -lrdimon \
  -Wall \
  -Wextra \
  -Wpedantic \
  -fno-exceptions") 
#set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
#set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

add_definitions(-D__SAMD21J18A__)
set(link_file "${CMAKE_SOURCE_DIR}/samd21/samd21j18a_flash.ld")

project(UbuntuBlink)
# enable_testing()
add_subdirectory(app)
add_subdirectory(cmsis)
add_subdirectory(samd21)
add_subdirectory(util)
add_subdirectory(perhipial)

#set(executable ${PROJECT_NAME}.elf)
#add_executable(executable EXCLUDE_FROM_ALL ${ARGN})
#set_target_properties(executable PROPERTIES
#  COMPILE_FLAGS "
#    -mcpu=cortex-m0 \
#    -mthumb \
#    -g"
#  LINK_FLAGS "
#    -T${link_file} \
#    -mthumb \
#    -mcpu=cortex-m0 \
#    -Wl,--gc-sections")
