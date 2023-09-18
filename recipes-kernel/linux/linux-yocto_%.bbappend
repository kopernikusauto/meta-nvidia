# nvidia module build fails if the scripts/basic/fixdep binary isn't present in
# the kernel build outputs

do_shared_workdir:append() {
    cp -r scripts $kerneldir/
    cp include/config/auto.conf $kerneldir/include/config/auto.conf
}
