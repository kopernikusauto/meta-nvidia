inherit module
do_compile[depends] += "virtual/kernel:do_shared_workdir"
EXTRA_OEMAKE:append = " SYSSRC=${STAGING_KERNEL_DIR} KERNEL_OUTPUT=${STAGING_KERNEL_BUILDDIR}"

do_precompile() {
    ln -s ${STAGING_INCDIR}/linux/stddef.h ${STAGING_INCDIR}/stddef.h
}

addtask do_precompile before do_compile after do_configure