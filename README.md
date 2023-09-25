# Overview

The meta-nvidia layer provides support for NVIDIA graphics drivers and related components for Yocto Project-based distributions. This layer includes recipes for building the NVIDIA binary graphics driver, the GL Vendor-Neutral Dispatch library (libglvnd), and modifications to the mesa package to ensure compatibility with NVIDIA's proprietary drivers.
# Contents

- Configuration: The layer.conf file contains the necessary configurations for the layer, including BBPATH, BBFILES, and other essential settings.
- Custom Licenses: The custom-licenses directory contains custom license files that may be required by the recipes in this layer.
- Recipes:
    - libglvnd: Provides the GL Vendor-Neutral Dispatch library.
    - mesa: Contains modifications to the mesa package to ensure compatibility with NVIDIA's proprietary drivers.
    - nvidia: Contains recipes for building NVIDIA's binary graphics driver and related components.

# Key Features

- libglvnd: The GL Vendor-Neutral Dispatch library allows multiple OpenGL implementations to coexist on the same system.
- NVIDIA Binary Graphics Driver: Provides support for NVIDIA GPUs, enabling hardware-accelerated graphics, CUDA support, and other NVIDIA-specific features.
- Mesa Modifications: Ensures that the open-source Mesa graphics library can coexist with NVIDIA's proprietary drivers.

# Usage

To use the meta-nvidia layer in your Yocto Project build:

- Clone the meta-nvidia repository to your local machine.
- Add the path to the meta-nvidia layer to your bblayers.conf file.
- Include the desired recipes in your image or build them individually using bitbake.

To use this layer, include it in your bblayers.conf and add the
following to your BSP, distro, or local config:

```bash
DISTRO_FEATURES:append = " x11 opengl"
DISTRO_FEATURES:remove = " wayland"
IMAGE_INSTALL:append = " libxshmfence cmake"
IMAGE_INSTALL:append = " packagegroup-core-buildessential"
IMAGE_INSTALL:append = " acpid"
IMAGE_INSTALL:append = " nvidia"
PREFERRED_PROVIDER_virtual/libgl = "libglvnd"
PREFERRED_PROVIDER_virtual/libgles1 = "libglvnd"
PREFERRED_PROVIDER_virtual/libgles3 = "libglvnd"
PREFERRED_PROVIDER_virtual/egl = "libglvnd"
PREFERRED_PROVIDER_virtual/libgl-native = "mesa-native"
PREFERRED_PROVIDER_virtual/nativesdk-libgl = "nativesdk-mesa-gl"
PREFERRED_PROVIDER_virtual/mesa = "libglvnd"
KERNEL_MODULE_AUTOLOAD:append = " nvidia nvidia-drm nvidia-modeset nvidia-uvm"
XSERVER = " \
    ${XSERVER_X86_BASE} \
    ${XSERVER_X86_EXT} \
    ${XSERVER_X86_MODESETTING} \
    nvidia"
```

# Dependencies

This layer depends on following layers:

    URI: git://git.yoctoproject.org/poky
    layers: meta
    branch: mickledore

    URI: git://git.yoctoproject.org/meta-openembedded
    layers: meta-oe
    branch: mickledore

    URI: git://git.yoctoproject.org/meta-virtualization
    layers: meta-virtualization
    branch: mickledore


# Compatibility

The meta-nvidia layer is ONLY compatible with the "mickledore" series of the Yocto Project.

# License

The recipes in this layer are licensed under various licenses, including MIT, BSD, and NVIDIA's proprietary license. Please refer to the individual recipe files and the custom-licenses directory for detailed licensing information.
Contributing

Contributions to the meta-nvidia layer are welcome. Please ensure that any changes are tested with the target hardware and do not introduce regressions.

# Disclaimer

This layer is not officially supported by NVIDIA Corporation. It is based on meta-nvidia from deprecated [OakLabsInc](https://github.com/OakLabsInc/meta-nvidia). Always refer to NVIDIA's official documentation and support channels for information related to NVIDIA products.