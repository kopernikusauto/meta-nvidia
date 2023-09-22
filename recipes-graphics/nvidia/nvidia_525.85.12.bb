include nvidia-base.inc
include nvidia-kernel-module.inc
include nvidia-libs.inc

SRC_URI[md5sum] = "93dc06f289a0157b95093437d5e4d97d"
SRC_URI[sha256sum] = "28dc6e779d784bc720afed22911920bd77ee39659a6aaa32696a5300ea27e8c4"

# DEPENDS += "glibc"
# do_precompile() {
#     ln -sf ${STAGING_INCDIR_NATIVE}/../lib/x86_64-kos-linux/gcc/x86_64-kos-linux/12.3.0/include/stddef.h ${S}/stddef.h
#     #ln -s ${STAGING_INCDIR}/linux/stddef.h ${S}/stddef.h
#     ln -sf ${STAGING_INCDIR_NATIVE}/../lib/x86_64-kos-linux/gcc/x86_64-kos-linux/12.3.0/include/stdarg.h ${S}/stdarg.h
#     #ln -s ${STAGING_INCDIR}/linux/stdarg.h ${S}/stdarg.h
# }
# do_precompile(){
#     for header in ${STAGING_INCDIR_NATIVE}/../lib/x86_64-kos-linux/gcc/x86_64-kos-linux/12.3.0/include/*.h; do
#         ln -sf $header ${S}/$(basename $header)
#     done
# }
#do_compile:prepend() {
#    for header in ${STAGING_INCDIR_NATIVE}/../lib/x86_64-kos-linux/gcc/x86_64-kos-linux/12.3.0/include/*.h; do
#        ln -sf $header ${S}/$(basename $header)
#    done
#}
# addtask do_precompile before do_compile after do_configure