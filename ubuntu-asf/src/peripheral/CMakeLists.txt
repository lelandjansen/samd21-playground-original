add_library(led STATIC
  #../asf/sam0/utils/syscalls/gcc/syscalls.c # <<< TODO: This is naughty
  led/led0.cc)
target_link_libraries(led
  ${VENDOR_LIBS})
target_include_directories(led
  INTERFACE ${CMAKE_SOURCE_DIR})
