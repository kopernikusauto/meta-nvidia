DESCRIPTION = "nvidia-settingsis NVIDIA's tool for dynamic configuration while the X server is running. See Chapter 23 for more information."


LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

SRC_URI = "https://download.nvidia.com/XFree86/nvidia-modprobe/nvidia-modprobe-430.14.tar.bz2 \
		  file://nvidia-modprobe.patch"
SRC_URI[md5sum] = "153de667b62f463f8793c76c2b57f649"
SRC_URI[sha256sum] = "74b11c8e85eed805d30c83426b55788a711e6fd1dc9a2139c3300c662f77693d"

inherit pkgconfig
DEPENDS += "\
	make \
"

RDEPENDS:${PN} = ""

do_compile:prepend(){
	
}

do_install:append() {
}

do_install () {
	install -m 755 -D ${S}/_out/Linux_x86_64/nvidia-modprobe ${D}${bindir}/nvidia-modprobe	
}
