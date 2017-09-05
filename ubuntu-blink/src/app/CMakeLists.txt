add_executable(blink 
  main.cc)
target_link_libraries(blink PRIVATE
  clock
  delay
  dynamic-memory
  led
  syscalls)

