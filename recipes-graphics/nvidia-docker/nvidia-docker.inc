SUMMARY = "Build and run Docker containers leveraging NVIDIA GPUs"
LICENSE = "BSD-2-Clause"

SRC_URI = " \
    git://github.com/NVIDIA/nvidia-docker.git;protocol=https \
    file://nvidia-docker.service \
"

S = "${WORKDIR}/git"

EXTRA_OEMAKE:append = " NV_DOCKER=/usr/bin/docker"

do_compile:append() {
    oe_runmake tarball
}

do_install:append() {
    tar -C ${S} -xJvf ${S}/dist/nvidia-docker_1.0.1_amd64.tar.xz
    install -D -m 755 ${S}/nvidia-docker/nvidia-docker ${D}${bindir}/nvidia-docker
    install -D -m 755 ${S}/nvidia-docker/nvidia-docker-plugin ${D}${bindir}/nvidia-docker-plugin
    install -D -m 644 ${WORKDIR}/nvidia-docker.service ${D}${systemd_unitdir}/system/nvidia-docker.service
}

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE:${PN} = "nvidia-docker.service"

FILES:${PN}:append= " \
    ${bindir} \
    ${systemd_unitdir} \
"

RDEPENDS:${PN}:append= " \
    docker \
    libcap-bin \
    nvidia \
"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
