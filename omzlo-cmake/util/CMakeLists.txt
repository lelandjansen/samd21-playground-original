project(util)

add_library(delay
  delay.cc)
target_link_libraries(delay
  samd21)
target_include_directories(delay
  INTERFACE ${CMAKE_SOURCE_DIR})

