DESCRIPTION = "NVIDIA CUDA Toolkit"
LICENSE = "Proprietary"
# LIC_FILES_CHKSUM = "file://../LICENSE;md5=2cc00be68c1227a7c42ff3620ef75d05"

# wget https://developer.download.nvidia.com/compute/cuda/12.0.1/local_installers/cuda_12.0.1_525.85.12_linux.run
# sudo sh cuda_12.0.1_525.85.12_linux.run
# Replace the version and checksum with the correct ones for your package
PV = "12.0.1"
PR = "r0"

SRC_URI = "https://developer.download.nvidia.com/compute/cuda/${PV}/local_installers/cuda_${PV}_525.85.12_linux.run"
SRC_URI[md5sum] = "2a5b80f322151e25ed792029e4571318"
SRC_URI[sha256sum] = "1b205a06272f1463f477276fdab903f3f666917c068e520738001e69c7a1875b"

S = "${WORKDIR}"

DEPENDS = "ncurses"

do_fetch[noexec] = "0"
do_unpack[noexec] = "0"
do_configure[noexec] = "1"
do_compile[noexec] = "1"

# Custom unpack function for the runfile
do_unpack() {
    chmod +x ${DL_DIR}/cuda_${PV}_525.85.12_linux.run
    ${DL_DIR}/cuda_${PV}_525.85.12_linux.run --extract=${WORKDIR}
}

do_install() {
    # Assuming the installer extracts to a predictable directory structure
    # Adjust these paths according to what you find after extraction

    # Toolkit installation
    ${WORKDIR}/cuda-linux.${PV}-x86_64.run --silent --toolkit --toolkitpath=${D}/usr/local/cuda-${PV}

    # Making the necessary symlinks and setting up environment variables
    echo "export PATH=\$PATH:/usr/local/cuda-${PV}/bin" > ${D}/etc/profile.d/cuda.sh
    echo "export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:/usr/local/cuda-${PV}/lib64" >> ${D}/etc/profile.d/cuda.sh
}

FILES_${PN} += "/usr/local/cuda-${PV}"
FILES_${PN}-doc += "/usr/share/doc/cuda-${PV}"

INSANE_SKIP_${PN} += "ldflags"
INSANE_SKIP_${PN}-dev += "ldflags"

# Adjust the package name as necessary
PACKAGES = "${PN} ${PN}-doc"

RDEPENDS_${PN} = "ncurses"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"= "1"
