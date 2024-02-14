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
    # wget -P ${DL_DIR} ${SRC_URI}
    # chmod +x ${DL_DIR}/cuda_12.0.1_525.85.12_linux.run
    echo "custom fetch"

}

do_unpack() {
    # Your existing unpack commands here

    # Debug: List the contents of WORKDIR
    ls -lah ${WORKDIR}
}

do_install() {   
    # Define the source path of the pre-installed CUDA Toolkit
    local cuda_preinstalled_dir="/opt/cuda-install"

    # Ensure the source directory exists
    if [ ! -d "${cuda_preinstalled_dir}" ]; then
        bbfatal "Pre-installed CUDA directory does not exist: ${cuda_preinstalled_dir}"
    fi

    # Define the destination directory within the Yocto build
    # This should match the intended path in the target root filesystem
    local cuda_dest_dir="${D}${prefix}/cuda"

    # Create the destination directory
    install -d ${cuda_dest_dir}

    # Copy the pre-installed CUDA Toolkit to the destination directory
    cp -a ${cuda_preinstalled_dir}/* ${cuda_dest_dir}/

    # Ensure executable permissions are correctly set on binaries
    # Adjust this command as necessary for your specific files and directories
    # find ${cuda_dest_dir} -type f -executable -exec chmod 755 {} \;

    # Check if installation was successful
    if [ "$(ls -A ${cuda_dest_dir})" ]; then
        echo "Installation successful. Copying CUDA Toolkit components..."

        # Recursively copy all contents to their respective locations
        cp -r ${cuda_extract_dir}/* ${D}${prefix}/cuda/

        echo "CUDA Toolkit installation completed."
    else
        bbfatal "Installation failed. CUDA Toolkit did not install any files."
    fi
else
    bbfatal "CUDA installer file not found in ${DL_DIR}."
fi
}

addtask do_custom_fetch before do_fetch
# addtask do_copy_installer_preinstall before do_install

FILES:${PN}:append= "${bindir}/* ${libdir}/* ${includedir}/*"

COMPATIBLE_HOST = "(x86_64).*-linux"

# PROVIDES = "cuda"

do_make_scripts[noexec] = "1"
INSANE_SKIP:${PN}:append = "ldflags already-stripped dev-so"