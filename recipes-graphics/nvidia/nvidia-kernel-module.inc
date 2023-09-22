inherit module
do_compile[depends] += "virtual/kernel:do_shared_workdir"
EXTRA_OEMAKE:append = " SYSSRC=${STAGING_KERNEL_DIR} KERNEL_OUTPUT=${STAGING_KERNEL_BUILDDIR}"
EXTRA_OEMAKE:append = " -I ${STAGING_INCDIR_NATIVE}/usr/lib/x86_64-kos-linux/gcc/x86_64-kos-linux/12.3.0/include"