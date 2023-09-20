DESCRIPTION = "nvidia-settingsis NVIDIA's tool for dynamic configuration while the X server is running. See Chapter 23 for more information."


LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

SRC_URI = "https://download.nvidia.com/XFree86/nvidia-xconfig/nvidia-xconfig-430.14.tar.bz2 \
		  file://nvidia-xconfig.patch"
SRC_URI[md5sum] = "fb26f51140fbc6adb06a85cdbfe2397c"
SRC_URI[sha256sum] = "676e20fbd8a80084dde5e675b0545ac1520c828106524853d1aee5bb8e8b9885"

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
	install -m 755 -D ${S}/_out/Linux_x86_64/nvidia-xconfig ${D}${bindir}/nvidia-xconfig		
}
