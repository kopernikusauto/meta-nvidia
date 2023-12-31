SUMMARY = "NVidia Binary Graphics Driver"
LICENSE = "NVIDIA-Proprietary"
LIC_FILES_CHKSUM = "file://../LICENSE;md5=2cc00be68c1227a7c42ff3620ef75d05"

NVIDIA_ARCHIVE_NAME = "NVIDIA-Linux-${TARGET_ARCH}-${PV}"
NVIDIA_SRC = "${WORKDIR}/${NVIDIA_ARCHIVE_NAME}"
# https://us.download.nvidia.com/tesla/${PV}/${NVIDIA_ARCHIVE_NAME}.run
SRC_URI = " \
		https://us.download.nvidia.com/tesla/525.85.12/NVIDIA-Linux-x86_64-525.85.12.run \
"

S = "${NVIDIA_SRC}/kernel"

do_unpack() {
	chmod +x ${DL_DIR}/NVIDIA-Linux-x86_64-525.85.12.run
	rm -rf ${NVIDIA_SRC}
	${DL_DIR}/NVIDIA-Linux-x86_64-525.85.12.run -x --target ${NVIDIA_SRC}
}

do_make_scripts[noexec] = "1"
