DESCRIPTION = "nvidia-settingsis NVIDIA's tool for dynamic configuration while the X server is running. See Chapter 23 for more information."


LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

SRC_URI = "https://download.nvidia.com/XFree86/nvidia-settings/nvidia-settings-430.14.tar.bz2 \
		  file://nvidia-settings.patch"
SRC_URI[md5sum] = "e283991662b5ca9e4b76b976552d62cc"
SRC_URI[sha256sum] = "f91232747bc255e652f0baada664ce0ffbc84c2a165f58456ca1db418fd63300"

inherit pkgconfig
DEPENDS += "\
	make \
	libx11 \
	libxrandr \
	libxv \
	libvdpau \
	libxxf86vm \
	gtk+ \
"

#RDEPENDS:${PN} = " libxxf86vm libglvnd libvdpau libxv libxrandr libx11"

do_compile:prepend(){
	
}

do_install:append() {
}

do_install () {
	install -m 755 -D ${S}/src/_out/Linux_x86_64/nvidia-settings ${D}${bindir}/nvidia-settings		
}
