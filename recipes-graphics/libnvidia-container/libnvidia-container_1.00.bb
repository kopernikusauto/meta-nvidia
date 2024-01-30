require libnvidia-container.inc

SUMMARY = "libNVIDIA Container for Yocto"

PACKAGECONFIG ??= ""
PACKAGECONFIG[seccomp] = "WITH_SECCOMP=yes,WITH_SECCOMP=no,libseccomp"

# We need to link with libelf, otherwise we need to
# include bmake-native which does not exist at the moment.
EXTRA_OEMAKE = 'EXCLUDE_BUILD_FLAGS=1 PLATFORM=${HOST_ARCH} WITH_NVCGO=no WITH_LIBELF=yes COMPILER=${@d.getVar('CC').split()[0]} REVISION=${SRCREV_libnvidia} ${PACKAGECONFIG_CONFARGS} \
                NVIDIA_MODPROBE_EXTRA_CFLAGS="${NVIDIA_MODPROBE_EXTRA_CFLAGS}"'
NVIDIA_MODPROBE_EXTRA_CFLAGS ?= "${DEBUG_PREFIX_MAP}"
export OBJCPY="${OBJCOPY}"

do_configure:append() {
    # Mark Nvidia modprobe as downloaded
    touch ${S}/deps/src/nvidia-modprobe-${NVIDIA_MODPROBE_VERSION}/.download_stamp
}

do_compile:prepend() {

    # get lsb_release
    install -m 0755 /usr/bin/lsb_release ${WORKDIR}/lsb_release

    # Copy nproc from the container's /usr/bin to the working directory
    install -m 0755 /usr/bin/nproc ${WORKDIR}/nproc

    # Copy bmake from the container's /usr/bin to the working directory
    install -m 0755 /usr/bin/bmake ${WORKDIR}/bmake

    # Ensure the copied bmake is used during the build
    export PATH=${WORKDIR}:$PATH
    
    #go fix
    export GOPATH="${WORKDIR}/go"
    export GOCACHE="${WORKDIR}/go-cache"
    mkdir -p ${GOPATH} ${GOCACHE}
}

do_compile:prepend() {
    export CURL="curl --insecure"
}

do_compile() {
    oe_runmake
}

do_install() {
    oe_runmake install DESTDIR=${D}
}

FILES_${PN} += "/usr/local/bin /usr/local/lib"
