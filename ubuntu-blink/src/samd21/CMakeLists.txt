project(samd21)

add_library(samd21j18a STATIC
  samd21j18a.c)
link_libraries(samd21j18a
  cmsis)
target_include_directories(samd21j18a
  INTERFACE ${CMAKE_SOURCE_DIR})

