project(app)
add_executable(blink
  startup_samd21.c
  system_samd21.c
  main.cc)
# https://stackoverflow.com/questions/32864689/cmake-how-to-add-dependency-on-linker-script-for-executable
set_target_properties(blink PROPERTIES 
#  LINK_DEPENDS samd21j18a_flash.ld
  LINK_FLAGS "\
    -T${PROJECT_SOURCE_DIR}/samd21j18a_flash.ld \
    -mthumb \
    -mcpu=cortex-m0 \
    -Wl,--gc-sections") 
target_link_libraries(blink PRIVATE
  clock
  delay
  dynamic-memory
  led
  samd21j18a
  syscalls)

