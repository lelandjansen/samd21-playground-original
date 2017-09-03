add_executable(blink 
  main.cc)

target_link_libraries(blink
  util_clock
  util_delay
  util_dynamic-memory
  util_reset
  util_syscalls
  util_wait)
