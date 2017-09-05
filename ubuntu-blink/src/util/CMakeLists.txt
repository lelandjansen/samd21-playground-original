project(util)

add_library(clock STATIC
  clock.cc)
target_link_libraries(clock
  reset
  samd21j18a)
target_include_directories(clock
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(delay STATIC
  delay.cc)
target_link_libraries(delay
  samd21j18a)
target_include_directories(delay
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(dynamic-memory STATIC
  dynamic-memory.cc)
target_include_directories(dynamic-memory
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(reset STATIC
  reset.cc)
target_link_libraries(reset
  samd21j18a)
target_include_directories(reset
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(syscalls STATIC
  syscalls.c)
#target_link_libraries(syscalls
#  samd21j18a)
target_include_directories(syscalls
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(wait STATIC
  wait.cc)
target_include_directories(wait
  INTERFACE ${CMAKE_SOURCE_DIR})

