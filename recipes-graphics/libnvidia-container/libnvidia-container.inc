DESCRIPTION = "libnvidia-container"
HOMEPAGE = "https://github.com/NVIDIA/libnvidia-container"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

SRC_URI = "git://github.com/NVIDIA/libnvidia-container.git;protocol=https;branch=main"
SRCREV = "a4ef85ebc86688eeef667271abbc7cd4f1110cf6"

DEPENDS += "ca-certificates-native"
DEPENDS = "curl-native"

S = "${WORKDIR}/git"
