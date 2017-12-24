add_executable(${TARGET_OUTPUT_NAME}
  ../asf/sam0/utils/syscalls/gcc/syscalls.c # <<< TODO: This is naughty
  main.cc)
target_link_libraries(${TARGET_OUTPUT_NAME}
  ${VENDOR_LIBS}
  #led
  )
