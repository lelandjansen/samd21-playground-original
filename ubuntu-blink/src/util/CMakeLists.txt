project(util)

add_library(clock STATIC
  clock.cc)

add_library(delay STATIC
  delay.cc)

add_library(dynamic-memory STATIC
  dynamic-memory.cc)

add_library(reset STATIC
  reset.cc)

add_library(syscalls STATIC
  syscalls.c)

add_library(wait STATIC
  wait.h)
