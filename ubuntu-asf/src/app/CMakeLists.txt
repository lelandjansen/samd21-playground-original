project(app)
add_executable(blink
  main.cc)
target_link_libraries(blink PRIVATE
  asf)
set_target_properties(blink PROPERTIES
  OUTPUT_NAME "blink.elf"
  LINK_FLAGS "\
    -T${link_file} \
    -mthumb \
    -mcpu=cortex-m0 \
    -Wl,--gc-sections")
