project(app)
add_executable(blink
  main.cc)
# https://stackoverflow.com/questions/32864689/cmake-how-to-add-dependency-on-linker-script-for-executable
#set_target_properties(blink PROPERTIES 
#  LINK_DEPENDS samd21j18a_flash.ld
#  LINK_FLAGS "\
#    -T${PROJECT_SOURCE_DIR}/build/samd21j18a_flash.ld \
#    -mthumb \
#    -mcpu=cortex-m0 \
#    -Wl,--gc-sections") 
target_link_libraries(blink PRIVATE
  build
  clock
  delay
  dynamic-memory
  led
  samd21j18a
  syscalls)

