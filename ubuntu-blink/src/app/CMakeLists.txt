project(app)
add_executable(blink
  main.cc
  ../samd21/startup_samd21.c
  ../samd21/system_samd21.c)
#target_include_directories(blink PRIVATE 
#  ../samd21
#  ../cmsis)
target_link_libraries(blink PRIVATE
  clock
  delay
  #dynamic-memory
  led
  #samd21
  #syscalls
  )
set_target_properties(blink PROPERTIES
  OUTPUT_NAME "blink.elf"
  LINK_FLAGS "\
    -T${link_file} \
    -mthumb \
    -mcpu=cortex-m0 \
    -Wl,--gc-sections")

