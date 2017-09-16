http://omzlo.com/articles/programming-samd21-using-atmel-ice-with-openocd

To install the latest version of CMake
```
sudo apt purge cmake
wget https://cmake.org/files/v3.9/cmake-3.9.2.tar.gz
tar --extract --gunzip --file cmake-3.9.2.tar.gz
cd cmake-3.9.1/
./bootstrap
make -j2
sudo make install
```

Latest version of GNU Arm Embedded Toolchain
```
https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2

tar -jxf gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2

```

