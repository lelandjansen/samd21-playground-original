project(cmsis)

add_library(cmsis_core STATIC
  cmsis_core.c)
target_link_libraries(cmsis_core
  samd21j18a)
target_include_directories(cmsis_core
  INTERFACE ${CMAKE_SOURCE_DIR})

