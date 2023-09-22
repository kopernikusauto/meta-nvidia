include nvidia-base.inc
include nvidia-kernel-module.inc
include nvidia-libs.inc

SRC_URI[md5sum] = "93cb0e95485cc2cb5670fc15a5cefe53"
SRC_URI[sha256sum] = "423b1d078e6385182f48c6e201e834b2eea193a622e04d613aa2259fce6e2266"

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