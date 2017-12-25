add_library(led STATIC
  led/led0.cc)
target_link_libraries(led
  ${VENDOR_LIBS})
target_include_directories(led
  INTERFACE ${CMAKE_SOURCE_DIR})
