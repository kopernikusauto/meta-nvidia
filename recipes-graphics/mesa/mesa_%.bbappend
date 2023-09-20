PACKAGECONFIG[glvnd] = "--enable-libglvnd,--disable-libglvnd,libglvnd"
PACKAGECONFIG:append = " glvnd"

PACKAGES:append = " libglx-mesa libglx-mesa-dev"
PACKAGES:remove = "libgl-mesa libegl-mesa libgles1-mesa libgles2-mesa"

PROVIDES:remove = "virtual/libgl virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa"

# We ONLY want glx
do_install:append() {
	rm -rf ${D}${includedir}/GL
	rm -rf ${D}${includedir}/GLES
	rm -rf ${D}${includedir}/KHR
	rm -rf ${D}${includedir}/EGL
	rm -rf ${D}${includedir}/GLES2
	rm -f ${D}${libdir}/pkgconfig/gl.pc
	rm -f ${D}${libdir}/pkgconfig/egl.pc
	rm -f ${D}${libdir}/pkgconfig/glesv1_cm.pc
	rm -f ${D}${libdir}/pkgconfig/glesv2.pc
	rm -f ${D}${libdir}/libEGL.so
	rm -f ${D}${libdir}/libGLESv1_CM.so
	rm -f ${D}${libdir}/libGLESv2.so
}

FILES:libglx-mesa:append = " \
 	${libdir}/libGLX_mesa.so.0.0.0 \
"

FILES:libglx-mesa-dev:append = " \
	${libdir}/libGLX_mesa.so.0 \
	${libdir}/libGLX_mesa.so \
"
RDEPENDS:libglx-mesa-dev:append = " libglx-mesa"
