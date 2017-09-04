project(addlib)
add_library(add
  add.cc)
#target_include_directories(add PUBLIC  
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib>  
#)
