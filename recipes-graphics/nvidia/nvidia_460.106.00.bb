include nvidia-base.inc
include nvidia-kernel-module.inc
include nvidia-libs.inc

SRC_URI[md5sum] = "93dc06f289a0157b95093437d5e4d97d"
SRC_URI[sha256sum] = "28dc6e779d784bc720afed22911920bd77ee39659a6aaa32696a5300ea27e8c4"

DEPENDS += "glibc"