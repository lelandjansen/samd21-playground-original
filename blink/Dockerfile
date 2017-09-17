FROM ubuntu:xenial

RUN apt-get update && apt-get install -y \
# CircleCI requirements
  git \
  ssh \
  tar \
  gzip \
  ca-certificates \
# Our requirements
  wget \
  bzip2 \
  build-essential

# GNU Arm Embedded Toolchain
ARG ARM_GCC_INSTALL_DIR=/usr/bin/gcc-arm-none-eabi
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2
RUN tar --extract --bzip2 --file gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2 
RUN mkdir -p ${ARM_GCC_INSTALL_DIR}
RUN mv gcc-arm-none-eabi-6-2017-q2-update/* ${ARM_GCC_INSTALL_DIR}
RUN rm gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2 && \
  rm -rf gcc-arm-none-eabi-6-2017-q2-update
ENV PATH="${GCC_ARM_INSTALL_DIR}/bin:${PATH}"

# CMake
RUN wget https://cmake.org/files/v3.9/cmake-3.9.2.tar.gz
RUN tar --extract --gunzip --file cmake-3.9.2.tar.gz
RUN cd cmake-3.9.2 && \
  ./bootstrap &&  \
  make -j2 && \
  make install -j2 
RUN rm cmake-3.9.2.tar.gz && \
  rm -rf cmake-3.9.2

