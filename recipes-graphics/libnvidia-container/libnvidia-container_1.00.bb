require libnvidia-container.inc

SUMMARY = "libNVIDIA Container for Yocto"

do_compile:prepend() {

    # Create a fake lsb_release script
    echo '#!/bin/sh' > ${WORKDIR}/lsb_release
    echo 'echo "CentaurusNova"' >> ${WORKDIR}/lsb_release
    chmod +x ${WORKDIR}/lsb_release

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
