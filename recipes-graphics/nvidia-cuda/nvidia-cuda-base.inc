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

}

do_unpack() {
    # Your existing unpack commands here

    # Debug: List the contents of WORKDIR
    ls -lah ${WORKDIR}
}

do_install() {
    
    echo "Listing WORKDIR contents:"
    ls -la ${WORKDIR}
    echo "Listing DL_DIR contents:"
    ls -la ${DL_DIR}

    if [ -f ${DL_DIR}/cuda_${PV}_525.85.12_linux.run ]; then
        chmod +x ${DL_DIR}/cuda_${PV}_525.85.12_linux.run
        # Create a directory for extraction
        install -d ${D}${prefix}/cuda
        
        install -d ${D}${prefix}/cuda/bin
        mkdir ${D}${prefix}/cuda/lib64
        install -d ${D}${prefix}/cuda/lib64
        install -d ${D}${prefix}/cuda/include
        install -d ${D}${prefix}/cuda/share
        install -d ${D}${prefix}/cuda/doc
        mkdir ${D}${prefix}/cuda/tmp
        # Extract the installer
        ${DL_DIR}/cuda_${PV}_525.85.12_linux.run --silent --toolkit --samples --extract=${D}${prefix}/cuda
    else
        bbfatal "CUDA installer file not found."
    fi

    # Install binaries, libraries, etc.
    install -d ${D}${bindir}
    install -d ${D}${libdir}

    # Example of installing specific components, adjust paths as necessary
    cp -r ${D}${prefix}/cuda/bin/* ${D}${bindir}/
    
    # cp -r ${D}${prefix}/cuda/lib64/* ${D}${libdir}/
    cp -r ${D}${prefix}/cuda/include/* ${D}${includedir}/
    # Copy the shared resources
    cp -r ${D}${prefix}/cuda/share/* ${D}${datadir}/

    # Handle documentation and additional components
    cp -r ${D}${prefix}/cuda/DOCS/* ${D}${docdir}/cuda/
    cp -r ${D}${prefix}/cuda/nsight* ${D}${prefix}/cuda/
    cp -r ${D}${prefix}/cuda/nvml ${D}${prefix}/cuda/
    cp -r ${D}${prefix}/cuda/nvvm ${D}${prefix}/cuda/
    cp -r ${D}${prefix}/cuda/extras ${D}${prefix}/cuda/
    cp -r ${D}${prefix}/cuda/gds* ${D}${prefix}/cuda/
    cp -r ${D}${prefix}/cuda/compute-sanitizer ${D}${prefix}/cuda/
    cp -r ${D}${prefix}/cuda/tools ${D}${prefix}/cuda/
    cp -r ${D}${prefix}/cuda/src ${D}${prefix}/cuda/

    # Ensure the EULA, README, and version.json are copied
    cp ${D}${prefix}/cuda/EULA.txt ${D}${docdir}/cuda/
    cp ${D}${prefix}/cuda/README ${D}${docdir}/cuda/
    cp ${D}${prefix}/cuda/version.json ${D}${docdir}/cuda/

    # Clean up the extraction directory if you wish
    rm -rf ${D}${prefix}/cuda
}
addtask do_custom_fetch before do_fetch
# addtask do_copy_installer_preinstall before do_install

FILES:${PN}:append= "${bindir}/* ${libdir}/* ${includedir}/*"

COMPATIBLE_HOST = "(x86_64).*-linux"

# PROVIDES = "cuda"

do_make_scripts[noexec] = "1"