cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(UbuntuBlink)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm-none-eabi)
set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS 
  -fno-exceptions
  # -Wall
  # -Werror
  # -Wextra
  )

# enable_testing()
add_subdirectory(app)
add_subdirectory(util)
add_subdirectory(perhipial)

