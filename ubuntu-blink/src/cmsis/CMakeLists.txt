project(cmsis)

add_library(cmsis STATIC
  cmsis.c)
target_link_libraries(cmsis PRIVATE
  samd21)
#    core_cm0plus.h)
#set_target_properties(cmsis PROPERTIES
#  LINKER_LANGUAGE C)
target_include_directories(cmsis
  INTERFACE ${CMAKE_SOURCE_DIR})

