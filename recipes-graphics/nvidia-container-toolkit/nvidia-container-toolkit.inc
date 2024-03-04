DESCRIPTION = "NVIDIA Container Toolkit"
HOMEPAGE = "https://github.com/NVIDIA/nvidia-container-toolkit"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://src/${GO_IMPORT}/LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

SRC_URI = "git://github.com/NVIDIA/nvidia-container-toolkit.git;protocol=https;branch=main"
SRCREV = "df9732dae475daeb0fcef1452a3acd9c74ca007c"

GO_IMPORT = "github.com/NVIDIA/nvidia-container-toolkit"

DEPENDS = " \
            curl-native ca-certificates-native go-native \
            coreutils-native \
            "

S = "${WORKDIR}/git"
