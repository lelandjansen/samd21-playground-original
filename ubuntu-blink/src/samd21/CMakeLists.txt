project(samd21)

add_library(samd21
  samd21.h)
target_link_libraries(samd21 PRIVATE
  cmsis)
target_include_directories(samd21
  INTERFACE ${CMAKE_SOURCE_DIR})

