# Edge Impulse Example: stand-alone inferencing (Himax WE-I Plus)

This runs an exported impulse on the Himax WE-I Plus development board. See the documentation at [Running your impulse locally (Himax WE-I Plus)](https://docs.edgeimpulse.com/docs/running-your-impulse-himax).

## How to build (Linux)

### Metaware Toolkit

1. Install the [DesignWare ARC MetaWare Toolkit](https://www.synopsys.com/dw/ipdir.php?ds=sw_metaware) and make sure `ccac` is in your PATH. You'll also need a valid ARC MetaWare license.
1. Create a build directory and initialize CMake:

    ```
    $ mkdir build-mw
    $ cd build-mw
    $ cmake -DCMAKE_TOOLCHAIN_FILE=toolchain.metaware.cmake ..
    ```

2. Build and link the application:

    ```
    $ make -j
    $ sh ../make-image.sh MW
    ```

### GNU

1. Install the [GNU Toolchain for DesignWare ARC processors](https://github.com/foss-for-synopsys-dwc-arc-processors/toolchain) and make sure `arc-elf32-gcc` is in your PATH.
1. Create a build directory and initialize CMake:

    ```
    $ mkdir build-gnu
    $ cd build-gnu
    $ cmake -DCMAKE_TOOLCHAIN_FILE=toolchain.gnu.cmake ..
    ```

2. Build and link the application:

    ```
    $ make -j
    $ sh ../make-image.sh GNU
    ```

## How to build (any other operating system using Docker)

### Metaware Toolkit

1. Note that you'll need a valid ARC MetaWare license to build.
1. Build the container:

    ```
    $ docker build -t himax-build -f Dockerfile .
    ```

1. Then set up your build environment:

    ```
    $ mkdir -p build-mw
    $ docker run --rm -it -v $PWD:/app himax-build /bin/bash -c "cd build-mw && cmake -DCMAKE_TOOLCHAIN_FILE=toolchain.metaware.cmake .."
    ```

1. And build and link the application:

    ```
    $ docker run --rm -it -v $PWD:/app:delegated -e SNPSLMD_LICENSE_FILE=27020@synopsys.edgeimpulse.com himax-build /bin/bash -c "cd build-mw && make -j && sh ../make-image.sh MW"
    ```

    Where you'll have to replace 27020@synopsys.edgeimpulse.com with your license server or license file.

### GNU

1. Build the container:

    ```
    $ docker build -t himax-build-gnu -f Dockerfile.gnu .
    ```

1. Then set up your build environment:

    ```
    $ mkdir -p build-gnu
    $ docker run --rm -it -v $PWD:/app himax-build-gnu /bin/bash -c "cd build-gnu && cmake -DCMAKE_TOOLCHAIN_FILE=toolchain.gnu.cmake .."
    ```

1. And build and link the application:

    ```
    $ docker run --rm -it -v $PWD:/app:delegated himax-build-gnu /bin/bash -c "cd build-gnu && make -j && sh ../make-image.sh GNU"
    ```

    Where you'll have to replace 27020@synopsys.edgeimpulse.com with your license server or license file.

## Flashing the binary

You'll need the [Edge Impulse CLI](https://docs.edgeimpulse.com/docs/cli-installation). Then flash the binary with:

```
$ himax-flash-tool --firmware-path image_gen_linux/out.img
```