add_library(button STATIC
  button/sw0.cc)
target_link_libraries(button
  ${vendor_libs})
target_include_directories(button
  INTERFACE ${CMAKE_SOURCE_DIR})

add_library(led STATIC
  #led/io1led.cc
  led/led0.cc)
target_link_libraries(led
  ${VENDOR_LIBS})
target_include_directories(led
  INTERFACE ${CMAKE_SOURCE_DIR})
