# Good read: https://devtalk.nvidia.com/default/topic/915640/unix-graphics-announcements-and-news/multiple-glx-client-libraries-in-the-nvidia-linux-driver-installer-package/

DESCRIPTION = "Linker and Installer of Nvidia Kernel modules, libs and binaries"
SECTION = "Installer Tools"
MAINTAINER = "Nauman Shakir <nshakir@kopernikusauto.com>"

base_lib64dir = "/lib64"

RDEPENDS:${PN}:remove =  " \
    libatk \
    libcairo \ 
    libgdk-pixbuf \
    glib-2.0 \
    libgtk+ \
    libgtk+3 \
    jansson \
    libpango \
    cairo \
    libx11 \
    libxxf86vm \
    "

do_install:append() {
	mkdir -p ${D}${libdir}/vdpau \
             ${D}${libdir}/xorg/modules/drivers \
	         ${D}${libdir}/xorg/modules/extensions \
             ${D}${datadir}/nvidia \
             ${D}${datadir}/glvnd/egl_vendor.d \
             ${D}${datadir}/X11/xorg.conf.d \
             ${D}${sysconfdir}/OpenCL/vendors/

	cp ${NVIDIA_SRC}/libnvidia-glcore.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libglxserver_nvidia.so.${PV} ${D}${libdir}/xorg/modules/extensions/
    cp ${NVIDIA_SRC}/libnvidia-tls.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libGLX_nvidia.so.${PV} ${D}${libdir}/
    install -m 444 ${NVIDIA_SRC}/nvidia-application-profiles-525.85.12-rc  ${D}${datadir}/nvidia/
    install -m 444 ${NVIDIA_SRC}/nvidia-application-profiles-525.85.12-key-documentation ${D}${datadir}/nvidia/
    cp ${NVIDIA_SRC}/libnvidia-glvkspirv.so.${PV} ${D}${libdir}/
    
    install -m 644  ${NVIDIA_SRC}/10_nvidia.json ${D}${datadir}/glvnd/egl_vendor.d/
    cp ${NVIDIA_SRC}/nvidia_drv.so ${D}${libdir}/xorg/modules/drivers/
    install -m 444 ${NVIDIA_SRC}/nvidia-drm-outputclass.conf ${D}${datadir}/X11/xorg.conf.d/nvidia-drm-outputclass.conf

    cp ${NVIDIA_SRC}/libnvidia-gtk2.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-gtk3.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-cfg.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-ml.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libvdpau_nvidia.so.${PV} ${D}${libdir}/vdpau/
    cp ${NVIDIA_SRC}/libcuda.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-opencl.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libOpenCL.so.1.0.0 ${D}${libdir}/

    install -m 444 ${NVIDIA_SRC}/nvidia.icd  ${D}${sysconfdir}/OpenCL/vendors/nvidia.icd

    if [ "$(ls ${NVIDIA_SRC}/*.so.* 2> /dev/null)" ]; then
        cp ${NVIDIA_SRC}/*.so.* ${D}${libdir}/
    fi

    ln -sf libglxserver_nvidia.so.${PV} ${D}${libdir}/xorg/modules/extensions/libglxserver_nvidia.so
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_nvidia.so.0
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_indirect.so.0


    ln -sf libnvidia-cfg.so.${PV} ${D}${libdir}/libnvidia-cfg.so.1
    ln -sf libnvidia-cfg.so.1 ${D}${libdir}/libnvidia-cfg.so

    ln -sf libnvidia-ml.so.${PV} ${D}${libdir}/libnvidia-ml.so.1
    ln -sf libnvidia-ml.so.1 ${D}${libdir}/libnvidia-ml.so

    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/vdpau/libvdpau_nvidia.so.1
    ln -sf vdpau/libvdpau_nvidia.so.1 ${D}${libdir}/libvdpau_nvidia.so

    ln -sf libcuda.so.${PV} ${D}${libdir}/libcuda.so.1
    ln -sf libcuda.so.1 ${D}${libdir}/libcuda.so

    ln -sf libnvidia-opencl.so.${PV} ${D}${libdir}/libnvidia-opencl.so.1
    ln -sf libnvidia-opencl.so.1 ${D}${libdir}/libnvidia-opencl.so

    ln -sf libnvidia-opencl.so.${PV} ${D}${libdir}/libnvidia-opencl.so.1
    ln -sf libOpenCL.so.1.0.0 ${D}${libdir}/libOpenCL.so.1.0
    ln -sf libOpenCL.so.1.0 ${D}${libdir}/libOpenCL.so.1
    ln -sf libOpenCL.so.1 ${D}${libdir}/libOpenCL.so

    ln -sf libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/libnvidia-ptxjitcompiler.so.1
    ln -sf libnvidia-ptxjitcompiler.so.1 ${D}${libdir}/libnvidia-ptxjitcompiler.so

    ln -sf libnvcuvid.so.${PV} ${D}${libdir}/libnvcuvid.so.1
    ln -sf libnvcuvid.so.1 ${D}${libdir}/libnvcuvid.so

    ln -sf libnvidia-encode.so.${PV} ${D}${libdir}/libnvidia-encode.so.1
    ln -sf libnvidia-encode.so.1 ${D}${libdir}/libnvidia-encode.so

    ln -sf libnvidia-ifr.so.${PV} ${D}${libdir}/libnvidia-ifr.so.1
    ln -sf libnvidia-ifr.so.1 ${D}${libdir}/libnvidia-ifr.so

    ln -sf libnvidia-fbc.so.${PV} ${D}${libdir}/libnvidia-fbc.so.1
    ln -sf libnvidia-fbc.so.1 ${D}${libdir}/libnvidia-fbc.so

    ln -sf libEGL_nvidia.so.${PV} ${D}${libdir}/libEGL_nvidia.so.0
    ln -sf libGLESv2_nvidia.so.${PV} ${D}${libdir}/libGLESv2_nvidia.so.2

    ln -sf libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/libGLESv1_CM_nvidia.so.1
    ln -sf libnvoptix.so.${PV} ${D}${libdir}/libnvoptix.so.1
    ln -sf libnvidia-opticalflow.so.${PV} ${D}${libdir}/libnvidia-opticalflow.so.1
    ln -sf libnvidia-opticalflow.so.1 ${D}${libdir}/libnvidia-opticalflow.so


    # nvidia
	mkdir -p ${D}${bindir}
    install -m 755 -D ${NVIDIA_SRC}/nvidia-settings ${D}${bindir}/nvidia-settings
    install -m 755 -D ${NVIDIA_SRC}/nvidia-debugdump ${D}${bindir}/nvidia-debugdump
    install -m 755 -D ${NVIDIA_SRC}/nvidia-smi ${D}${bindir}/nvidia-smi
    install -m 755 -D ${NVIDIA_SRC}/nvidia-modprobe ${D}${bindir}/nvidia-modprobe
    #install -m 755 -D ${NVIDIA_SRC}/nvidia-xconfig ${D}${bindir}/nvidia-xconfig
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-server ${D}${bindir}/nvidia-cuda-mps-server
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control ${D}${bindir}/nvidia-cuda-mps-control
    install -m 755 -D ${NVIDIA_SRC}/nvidia-persistenced ${D}${bindir}/nvidia-persistenced

    # nvidia-doc
	mkdir -p ${D}${datadir}/doc/nvidia ${D}${mandir}/man1
    cp -r ${NVIDIA_SRC}/html ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/NVIDIA_Changelog ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/README.txt ${D}${datadir}/doc/nvidia/
    install -m 444 -D ${NVIDIA_SRC}/nvidia-settings.1.gz ${D}${mandir}/man1/nvidia-settings.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-smi.1.gz ${D}${mandir}/man1/nvidia-smi.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-xconfig.1.gz ${D}${mandir}/man1/nvidia-xconfig.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control.1.gz ${D}${mandir}/man1/nvidia-cuda-mps-control.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-persistenced.1.gz ${D}${mandir}/man1/nvidia-persistenced.1.gz
}


# Very important fix to allow nvidia-binaries to run
do_install:append() {
    if [ ! -d ${D}${base_lib64dir} ]; then
        mkdir -p ${D}${base_lib64dir}
    fi

    if [ ! -e ${D}${base_lib64dir}/ld-linux-x86-64.so.2 ]; then
        ln -s ${base_libdir}/ld-linux-x86-64.so.2 ${D}${base_lib64dir}/ld-linux-x86-64.so.2
    fi
}

FILES:${PN}:append= "${base_lib64dir} ${base_lib64dir}/ld-linux-x86-64.so.2"


do_make_scripts[noexec] = "1"

# REQUIRED_DISTRO_FEATURES = "x11"

FILES:${PN}:append= " \
	${libdir} \
	${bindir} \
    ${datadir} \
    ${sysconfdir} \
"

FILES:${PN}-doc:append= " \
	${mandir} \
	${datadir}/doc/nvidia \
"

RDEPENDS:${PN}:append= " \
	xserver-xorg-module-libwfb \
    libvdpau \
"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP:${PN}:append = "ldflags already-stripped dev-so"
INSANE_SKIP_libgl-nvidia:append = "ldflags"
