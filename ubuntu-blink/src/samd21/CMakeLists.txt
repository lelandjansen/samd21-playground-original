project(samd21)

add_library(samd21 STATIC
  samd21.c)
#  samd21.h)
#set_target_properties(samd21 PROPERTIES
#  LINKER_LANGUAGE C)
target_link_libraries(samd21 PRIVATE
  cmsis)
target_include_directories(samd21
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(startup STATIC
  startup_samd21.c
  system_samd21.c)
target_link_libraries(startup PRIVATE
  cmsis)

