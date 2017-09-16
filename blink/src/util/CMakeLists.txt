project(util)

add_library(clock
  clock.cc)
target_link_libraries(clock
  reset
  samd21)
target_include_directories(clock
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(delay
  delay.cc)
target_link_libraries(delay
  samd21)
target_include_directories(delay
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(reset
  reset.cc)
target_link_libraries(reset PRIVATE
  samd21
  wait)
target_include_directories(reset
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(wait INTERFACE) 
target_sources(wait INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/wait.h)
target_include_directories(wait
  INTERFACE ${CMAKE_SOURCE_DIR})

