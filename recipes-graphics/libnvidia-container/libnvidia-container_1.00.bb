require libnvidia-container.inc

SUMMARY = "libNVIDIA Container for Yocto"

do_compile:prepend() {
    # Copy nproc from the container's /usr/bin to the working directory
    install -m 0755 /usr/bin/nrpoc ${WORKDIR}/bmake
    export PATH=${WORKDIR}:$PATH

}
do_compile:prepend() {
    # Copy bmake from the container's /usr/bin to the working directory
    install -m 0755 /usr/bin/bmake ${WORKDIR}/bmake

    # Ensure the copied bmake is used during the build
    export PATH=${WORKDIR}:$PATH
    # Set the number of make jobs to the number of available CPU cores
    # export MAKEFLAGS="-j ${@oe.utils.cpu_count()}"
}

do_compile:prepend() {
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
