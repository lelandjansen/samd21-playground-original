FROM ubuntu:xenial

RUN apt-get update

# CircleCI requirements
RUN apt-get install -y \
  git \
  ssh \
  tar \
  gzip \
  ca-certificates

# Our general requirements
RUN apt-get install -y \
  wget \
  bzip2 \
  build-essential \
  software-properties-common

# GNU Arm Embedded Toolchain
ARG ARM_GCC_INSTALL_DIR=/usr/bin/gcc-arm-none-eabi
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2
RUN tar --extract --bzip2 --file gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2 
RUN mkdir -p ${ARM_GCC_INSTALL_DIR}
RUN mv gcc-arm-none-eabi-6-2017-q2-update/* ${ARM_GCC_INSTALL_DIR}
RUN rm gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2 && \
  rm -rf gcc-arm-none-eabi-6-2017-q2-update
ENV PATH "/usr/bin/gcc-arm-none-eabi/bin:$PATH"

# LLVM
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
# Fingerprint: 6084 F3CF 814B 57C1 CF12 EFD5 15CF 4D18 AF4F 7421
RUN apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-5.0 main" 
RUN apt-get update && apt-get install -y \
  clang-5.0 \
  lldb-5.0 \
  lld-5.0 \
  clang-tidy-5.0 \
  clang-format-5.0

# CMake
RUN wget https://cmake.org/files/v3.9/cmake-3.9.2.tar.gz
RUN tar --extract --gunzip --file cmake-3.9.2.tar.gz
RUN cd cmake-3.9.2 && \
  ./bootstrap &&  \
  make -j2 && \
  make install -j2 
RUN rm cmake-3.9.2.tar.gz && \
  rm -rf cmake-3.9.2

