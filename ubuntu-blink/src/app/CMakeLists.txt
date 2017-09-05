add_executable(blink 
  main.cc)
target_link_libraries(blink
  clock
  delay
  dynamic-memory
  led
  syscalls)

