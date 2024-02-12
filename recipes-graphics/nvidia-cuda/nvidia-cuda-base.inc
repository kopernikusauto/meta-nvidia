DESCRIPTION = "NVIDIA CUDA Toolkit"
SECTION = "devel"
LICENSE = "CLOSED"

PV = "12.0.1"
PR = "r0"

SRC_URI = "https://developer.download.nvidia.com/compute/cuda/${PV}/local_installers/cuda_${PV}_525.85.12_linux.run"
SRC_URI[md5sum] = "2a5b80f322151e25ed792029e4571318"
SRC_URI[sha256sum] = "1b205a06272f1463f477276fdab903f3f666917c068e520738001e69c7a1875b"

S = "${WORKDIR}"

# Depend on libcudart and any other libraries/tools your applications need

DEPENDS = "ncurses"
# Allow the recipe to fetch the CUDA Toolkit installer
LICENSE_FLAGS_ACCEPTED = "commercial"

inherit cuda

do_fetch[noexec] = "1"
do_unpack[noexec] = "1"
do_configure[noexec] = "1"

do_compile() {
    :
}

do_install() {
    # Create a temporary directory for extraction
    install -d ${D}${prefix}/cuda
    # Extract the CUDA run file
    sh ${WORKDIR}/cuda_${PV}_525.85.12_linux.run --extract=${D}${prefix}/cuda

    # Install binaries, libraries, etc.
    install -d ${D}${bindir}
    install -d ${D}${libdir}

    # Example of installing specific components, adjust paths as necessary
    cp -r ${D}${prefix}/cuda/bin/* ${D}${bindir}/
    cp -r ${D}${prefix}/cuda/lib64/* ${D}${libdir}/
    cp -r ${D}${prefix}/cuda/include/* ${D}${includedir}/

    # Clean up the extraction directory if you wish
    rm -rf ${D}${prefix}/cuda
}

FILES:${PN}:append= "${bindir}/* ${libdir}/* ${includedir}/*"

COMPATIBLE_HOST = "(x86_64).*-linux"

# PROVIDES = "cuda"

