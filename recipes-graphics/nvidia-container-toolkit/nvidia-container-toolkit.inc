DESCRIPTION = "NVIDIA Container Toolkit"
HOMEPAGE = "https://github.com/NVIDIA/nvidia-container-toolkit"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://src/${GO_IMPORT}/LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

SRC_URI = "git://github.com/NVIDIA/nvidia-container-toolkit.git;protocol=https;branch=main"
SRCREV = "f0545dd9797ade63355f751946abb2b01170da7d"

GO_IMPORT = "github.com/NVIDIA/nvidia-container-toolkit"

DEPENDS = " \
            curl-native ca-certificates-native go-native \
            coreutils-native \
            "

S = "${WORKDIR}/git"
