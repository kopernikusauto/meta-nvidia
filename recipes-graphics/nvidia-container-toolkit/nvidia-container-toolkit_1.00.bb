require nvidia-container-toolkit.inc

SUMMARY = "NVIDIA Container Toolkit for Yocto"

inherit go

do_compile() {
    echo "Current directory: $(pwd)"
    ls -alh
    oe_runmake -C ${S} cmds
    
}

do_install() {
    # Create the target directories in the image file system
    install -d ${D}${bindir}
    
    # Copy each binary to the target directory
    install -m 0755 ${S}/nvidia-container-runtime ${D}${bindir}
    install -m 0755 ${S}/nvidia-container-runtime.cdi ${D}${bindir}
    install -m 0755 ${S}/nvidia-container-runtime-hook ${D}${bindir}
    install -m 0755 ${S}/nvidia-container-runtime.legacy ${D}${bindir}
    install -m 0755 ${S}/nvidia-ctk ${D}${bindir}
}


FILES_${PN} += "/usr/local/*"