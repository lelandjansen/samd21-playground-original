project(cmsis)
add_library(cmsis INTERFACE)
target_sources(cmsis INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/core_cm0plus.h)
target_link_libraries(cmsis INTERFACE
    samd21)
target_include_directories(cmsis
    INTERFACE ${CMAKE_SOURCE_DIR})

