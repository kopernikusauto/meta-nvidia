require nvidia-container-toolkit.inc

SUMMARY = "NVIDIA Container Toolkit for Yocto"

DEPENDS += "libnvidia-container"

do_compile() {
    oe_runmake
}

do_install() {
    oe_runmake install DESTDIR=${D}
}

FILES_${PN} += "/usr/local/bin /usr/local/lib"
