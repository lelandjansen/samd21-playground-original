project(app)

add_executable(app
  ${CMAKE_SOURCE_DIR}/samd21/startup_samd21.c
  main.cc)
target_link_libraries(app
  delay
  led)
set_target_properties(app PROPERTIES
  OUTPUT_NAME "${PROJECT_NAME}.elf"
  LINK_FLAGS "\
    -T${link_file} \
    -mthumb \
    -mcpu=cortex-m0 \
    -Wl,--gc-sections")

