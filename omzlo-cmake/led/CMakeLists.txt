project(led)

add_library(led
  led.cc)
target_link_libraries(led
  samd21)
target_include_directories(led
  INTERFACE ${CMAKE_SOURCE_DIR})

