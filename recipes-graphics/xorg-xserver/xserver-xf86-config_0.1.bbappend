FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"
SRC_URI:append = " file://nvidia.conf"

do_install:append() {
	install -m 0644 -D ${WORKDIR}/nvidia.conf ${D}${sysconfdir}/X11/xorg.conf.d/nvidia.conf
}
