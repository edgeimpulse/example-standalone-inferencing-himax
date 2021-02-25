FROM ubuntu:20.04

WORKDIR /app

RUN apt update && apt install -y wget build-essential

# Install recent CMake
RUN mkdir -p /opt/cmake && \
    cd /opt/cmake && \
    wget https://github.com/Kitware/CMake/releases/download/v3.19.0-rc3/cmake-3.19.0-rc3-Linux-x86_64.sh && \
    sh cmake-3.19.0-rc3-Linux-x86_64.sh --prefix=/opt/cmake --skip-license && \
    ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake

# Grab toolchain
RUN mkdir -p /opt/arc_gnu && \
    cd /opt/arc_gnu && \
    wget https://github.com/foss-for-synopsys-dwc-arc-processors/toolchain/releases/download/arc-2020.09-release/arc_gnu_2020.09_prebuilt_elf32_le_linux_install.tar.gz && \
    tar xf arc_gnu_2020.09_prebuilt_elf32_le_linux_install.tar.gz

# Add to PATH
ENV PATH="${PATH}:/opt/arc_gnu/arc_gnu_2020.09_prebuilt_elf32_le_linux_install/bin/"
