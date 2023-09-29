# glamor forces xserver-xorg to depend on virtual/mesa, which
# we want to avoid because we're using libglvnd

PACKAGECONFIG:remove = "glx dri glamor xwayland"
DEPENDS:append = " libxshmfence"

#add xinerama option to build with xinerama extension
PACKAGECONFIG:append = " xinerama"

INSANE_SKIP:${PN}:append = "xorg-driver-abi xorg-abi-video-25"
