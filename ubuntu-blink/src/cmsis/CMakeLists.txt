project(cmsis)

add_library(cmsis STATIC
    core_cm0plus.h)
target_include_directories(cmsis
  INTERFACE ${CMAKE_SOURCE_DIR})

