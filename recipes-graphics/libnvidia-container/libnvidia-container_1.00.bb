require libnvidia-container.inc

SUMMARY = "libNVIDIA Container for Yocto"

do_copy_ssl_certs() {
    install -d ${WORKDIR}/recipe-sysroot-native/etc/ssl/certs
    install -m 0644 /etc/ssl/certs/ca-certificates.crt ${WORKDIR}/recipe-sysroot-native/etc/ssl/certs/
}

addtask do_copy_ssl_certs before do_compile

do_compile() {
    oe_runmake
}

do_install() {
    oe_runmake install DESTDIR=${D}
}

FILES_${PN} += "/usr/local/bin /usr/local/lib"
