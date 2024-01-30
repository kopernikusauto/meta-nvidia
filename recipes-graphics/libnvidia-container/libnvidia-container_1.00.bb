require libnvidia-container.inc

SUMMARY = "libNVIDIA Container for Yocto"

do_compile_prepend() {
    export CURL="curl --insecure"
}

do_compile() {
    oe_runmake
}

do_install() {
    oe_runmake install DESTDIR=${D}
}

FILES_${PN} += "/usr/local/bin /usr/local/lib"
