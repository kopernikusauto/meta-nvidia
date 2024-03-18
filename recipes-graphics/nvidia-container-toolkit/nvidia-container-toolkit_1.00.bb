require nvidia-container-toolkit.inc

SUMMARY = "NVIDIA Container Toolkit for Yocto"

GO_INSTALL = "${GO_IMPORT}/cmd/..."
# The go-nvml symbol lookup functions *require* lazy dynamic symbol resolution
SECURITY_LDFLAGS = ""
LDFLAGS += "-Wl,-z,lazy"
GO_LINKSHARED = ""

REQUIRED_DISTRO_FEATURES = "virtualization"

inherit go go-mod features_check

do_compile() {
    echo "Current directory: $(pwd)"
    ls -alh
    oe_runmake -C ${S}/src/${GO_IMPORT} cmds
    
}

do_install(){
    go_do_install
    install -d ${D}${sysconfdir}/nvidia-container-runtime
    install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime ${D}${bindir}
    install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime-hook ${D}${bindir}
    install -m 0644 ${S}/src/${GO_IMPORT}/config/config.toml.ubuntu+jetpack ${D}${sysconfdir}/nvidia-container-runtime/config.toml
    sed -i -e's,ldconfig\.real,ldconfig,' ${D}${sysconfdir}/nvidia-container-runtime/config.toml
    ln -sf nvidia-container-toolkit ${D}${bindir}/nvidia-container-runtime-hook
}

# do_install() {
#     # Create the target directories in the image file system
#     install -d ${D}${bindir}
    
#     # Copy each binary to the target directory
#     install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime ${D}${bindir}
#     install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime.cdi ${D}${bindir}
#     install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime-hook ${D}${bindir}
#     install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-container-runtime.legacy ${D}${bindir}
#     install -m 0755 ${S}/src/${GO_IMPORT}/nvidia-ctk ${D}${bindir}

#     ln -sf nvidia-container-runtime-hook ${D}${bindir}/nvidia-container-toolkit
# }

INSANE_SKIP:${PN} += "already-stripped buildpaths"
INSANE_SKIP:${PN}:append = "already-stripped buildpaths"
FILES_${PN} += "/usr/local/*"

RDEPENDS:${PN} = "\
    libnvidia-container \
    "