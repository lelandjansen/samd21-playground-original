project(samd21)

add_library(samd21 INTERFACE)
target_sources(samd21 INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/samd21.h)
target_link_libraries(samd21 INTERFACE
  cmsis)
target_include_directories(samd21
  INTERFACE ${CMAKE_SOURCE_DIR})

