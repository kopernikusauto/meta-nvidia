DESCRIPTION = "libnvidia-container"
HOMEPAGE = "https://github.com/NVIDIA/libnvidia-container"
LICENSE = "Apache-2.0"
# LIC_FILES_CHKSUM = "file://LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

LIC_FILES_CHKSUM = "\
    file://LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57 \
    file://deps/src/nvidia-modprobe-${NVIDIA_MODPROBE_VERSION}/modprobe-utils/nvidia-modprobe-utils.c;endline=22;md5=8f11a22ea12c5aecde3340212f7fc9a1 \
    file://deps/src/nvidia-modprobe-${NVIDIA_MODPROBE_VERSION}/modprobe-utils/pci-enum.h;endline=29;md5=ca948b6fabc48e616fccbf17247feebf \
    file://deps/src/nvidia-modprobe-${NVIDIA_MODPROBE_VERSION}/modprobe-utils/pci-sysfs.c;endline=25;md5=0449248350efd54938e7f8d25af965cb \
"

ELF_TOOLCHAIN_VERSION = "0.7.1"
NVIDIA_MODPROBE_VERSION = "550.40.07"
LIBTIRPC_VERSION = "1.3.2"

SRC_URI = "git://github.com/NVIDIA/libnvidia-container.git;protocol=https;branch=main \
           git://github.com/NVIDIA/nvidia-modprobe.git;protocol=https;branch=main;name=modprobe;destsuffix=git/deps/src/nvidia-modprobe-${NVIDIA_MODPROBE_VERSION} \"

# SRCREV = "a4ef85ebc86688eeef667271abbc7cd4f1110cf6"
SRCREV_libnvidia = "a4ef85ebc86688eeef667271abbc7cd4f1110cf6"
# Nvidia modprobe version 495.44
SRCREV_modprobe = "d6bce304f30b6661c9ab6a993f49340eafca7a7e"
SRCREV_FORMAT = "libnvidia_modprobe"

DEPENDS = " \
            curl-native ca-certificates-native go-native \
            coreutils-native \
            pkgconfig-native \
            libcap \
            elfutils \
            libtirpc \
            ldconfig-native \        
            "

S = "${WORKDIR}/git"
