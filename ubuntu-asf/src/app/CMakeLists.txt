add_executable(${TARGET_OUTPUT_NAME}
  main.cc)
target_link_libraries(${TARGET_OUTPUT_NAME}
  ${VENDOR_LIBS}
  button
  led)
