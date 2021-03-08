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
    wget --load-cookies /tmp/cookies.txt "https://docs.google.com/uc?export=download&confirm=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate 'https://docs.google.com/uc?export=download&id=1LXLsmvS_zW9ak6XbnermdbgOW8wzxf2a' -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=1LXLsmvS_zW9ak6XbnermdbgOW8wzxf2a" -O arc_gnu_ei_prebuilt_minimal_elf32_le_linux_install.tar.gz && rm -rf /tmp/cookies.txt &&\
    tar xf arc_gnu_ei_prebuilt_minimal_elf32_le_linux_install.tar.gz

# Add to PATH
ENV PATH="${PATH}:/opt/arc_gnu/arc_gnu_ei_prebuilt_minimal_elf32_le_linux_install/bin/"
