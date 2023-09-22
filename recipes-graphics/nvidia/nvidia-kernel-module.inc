inherit module
do_compile[depends] += "virtual/kernel:do_shared_workdir"
EXTRA_OEMAKE:append = " SYSSRC=${STAGING_KERNEL_DIR} KERNEL_OUTPUT=${STAGING_KERNEL_BUILDDIR} -I ${STAGING_INCDIR}/linux"