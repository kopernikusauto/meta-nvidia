DESCRIPTION = "NVIDIA Container Toolkit"
HOMEPAGE = "https://github.com/NVIDIA/nvidia-container-toolkit"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://src/${GO_IMPORT}/LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

SRC_URI = "git://github.com/NVIDIA/nvidia-container-toolkit.git;protocol=https;branch=5605d19"
SRCREV = "5605d191332dcfeea802c4497360d60a65c7887e"

SRC_URI += "file://config.toml"

GO_IMPORT = "github.com/NVIDIA/nvidia-container-toolkit"

DEPENDS = " \
            curl-native ca-certificates-native go-native \
            coreutils-native \
            "

S = "${WORKDIR}/git"
