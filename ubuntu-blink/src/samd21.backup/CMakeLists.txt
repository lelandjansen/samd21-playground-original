project(samd21)

add_library(samd21j18a STATIC
  samd21j18a.c)
target_link_libraries(samd21j18a PRIVATE
  cmsis_core)
target_include_directories(samd21j18a
  INTERFACE ${CMAKE_SOURCE_DIR})

