#!/bin/bash
arm-none-eabi-gdb -iex "target extended-remote localhost:3333" build/omzlo-cmake.elf

