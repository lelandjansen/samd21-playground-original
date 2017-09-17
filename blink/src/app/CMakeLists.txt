project(app)

add_executable(app
  ${CMAKE_SOURCE_DIR}/samd21/interrupt-handlers.c
  ${CMAKE_SOURCE_DIR}/samd21/startup.c
  ${CMAKE_SOURCE_DIR}/util/dynamic-memory.cc
  ${CMAKE_SOURCE_DIR}/util/syscalls.c
  main.cc)
target_link_libraries(app
  clock
  delay
  led)
set_target_properties(app PROPERTIES
  OUTPUT_NAME "${PROJECT_NAME}.elf"
  LINK_FLAGS "\
    -T${link_file} \
    -mthumb \
    -mcpu=cortex-m0 \
    -Wl,--gc-sections")

