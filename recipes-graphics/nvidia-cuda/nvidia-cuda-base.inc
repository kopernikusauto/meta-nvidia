DESCRIPTION = "NVIDIA CUDA Toolkit"
SECTION = "devel"
LICENSE = "CLOSED"

PV = "12.0.1"
PR = "r0"

SRC_URI = "https://developer.download.nvidia.com/compute/cuda/${PV}/local_installers/cuda_${PV}_525.85.12_linux.run"
# SRC_URI = "file://cuda_12.0.1_525.85.12_linux.run"

SRC_URI[md5sum] = "2a5b80f322151e25ed792029e4571318"
SRC_URI[sha256sum] = "1b205a06272f1463f477276fdab903f3f666917c068e520738001e69c7a1875b"

S = "${WORKDIR}"

# Depend on libcudart and any other libraries/tools your applications need

DEPENDS = "ncurses"
# Allow the recipe to fetch the CUDA Toolkit installer
LICENSE_FLAGS_ACCEPTED = "commercial"

# inherit cuda

do_fetch[noexec] = "1"
do_unpack[noexec] = "1"
do_configure[noexec] = "1"

do_compile() {
    :
}
do_custom_fetch() {
    wget -P ${DL_DIR} ${SRC_URI}
    chmod +x ${DL_DIR}/cuda_12.0.1_525.85.12_linux.run
    echo "Listing DL_DIR contents:"
    ls -la ${DL_DIR}
    cp ${DL_DIR}/cuda_${PV}_525.85.12_linux.run ${WORKDIR}/
    echo "Listing WORKDIR contents:"
    ls -la ${WORKDIR}

}

do_unpack() {
    # Your existing unpack commands here

    # Debug: List the contents of WORKDIR
    ls -lah ${WORKDIR}
}
do_copy_installer_preinstall() {
    echo "Listing DL_DIR contents:"
    ls -la ${DL_DIR}
    cp ${DL_DIR}/cuda_${PV}_525.85.12_linux.run ${WORKDIR}/
    chmod +x ${WORKDIR}/cuda_${PV}_525.85.12_linux.run
    echo "Listing WORKDIR contents:"
    ls -la ${WORKDIR}
}
do_install() {
    
    echo "Listing WORKDIR contents:"
    ls -la ${WORKDIR}
    echo "Listing DL_DIR contents:"
    ls -la ${DL_DIR}

    if [ -f ${WORKDIR}/cuda_${PV}_525.85.12_linux.run ]; then
        chmod +x ${WORKDIR}/cuda_${PV}_525.85.12_linux.run
        # Create a directory for extraction
        install -d ${D}${prefix}/cuda
        # Extract the installer
        ${WORKDIR}/cuda_${PV}_525.85.12_linux.run --extract=${D}${prefix}/cuda
    else
        bbfatal "CUDA installer file not found."
    fi

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
addtask do_custom_fetch before do_fetch
# addtask do_copy_installer_preinstall before do_install

FILES:${PN}:append= "${bindir}/* ${libdir}/* ${includedir}/*"

COMPATIBLE_HOST = "(x86_64).*-linux"

# PROVIDES = "cuda"

