FROM ubuntu:20.04
MAINTAINER ckoyama<ckoyama.1996@gmail.com>

ENV NSLCORE=/opt/nslcore/linux/x86_64
# Quartus is not required if you don't use FPGA
ENV QUARTUS=/opt/intelFPGA_lite/20.1/quartus/bin
# Install directory for RISCV toolchain
ENV RISCV=/opt/riscv
ENV PATH=$RISCV/bin:$QUARTUS:$NSLCORE:$PATH
ENV USER=root
ENV HOME=/root
ENV DEBIAN_FRONTEND=noninteractive

WORKDIR ${HOME}
RUN apt update && apt install -y build-essential pkg-config texinfo libtool libusb-dev autoconf libusb-1.0-0-dev  libftdi-dev curl git libtcl

RUN mkdir -p /opt/nslcore
RUN curl https://ip-arch.jp/unsupported/nslcore-x86_64-linux-20210228-90.tar.gz | tar xvz -C /opt/nslcore
WORKDIR ${NSLCORE}

WORKDIR ${HOME}
