require nvidia-container-toolkit.inc

SUMMARY = "NVIDIA Container Toolkit for Yocto"

# The go-nvml symbol lookup functions *require* lazy dynamic symbol resolution
SECURITY_LDFLAGS = ""
LDFLAGS += "-Wl,-z,lazy"
GO_LINKSHARED = ""

inherit go

do_compile() {
    echo "Current directory: $(pwd)"
    ls -alh
    oe_runmake -C ${S}/src/${GO_IMPORT} cmds
    
}

do_install() {
    # Create the target directories in the image file system
    install -d ${D}${bindir}
    
    # Copy each binary to the target directory
    install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime ${D}${bindir}
    install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime.cdi ${D}${bindir}
    install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime-hook ${D}${bindir}
    install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime.legacy ${D}${bindir}
    install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-ctk ${D}${bindir}
}

INSANE_SKIP:${PN} += "already-stripped"

FILES_${PN} += "/usr/local/*"