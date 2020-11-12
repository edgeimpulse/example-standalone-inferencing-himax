# example-standalone-inferencing-himax

Builds and runs an exported impulse on the Himax WE-I Plus development board.

## How to build (locally)

1. Clone this repository.
2. Create a build directory and initialize CMake:

    ```
    $ mkdir build
    $ cd build
    $ cmake ..
    ```

3. Build and link the application:

    ```
    $ make -j
    $ sh ../make-image.sh
    ```

## How to build (Docker)

1. Clone this repository.
1. Build the container:

    ```
    $ docker build -t himax-build .
    ```

1. Then set up your build environment:

    ```
    $ mkdir -p build && mkdir -p image_gen_linux_v3
    $ docker run --rm -it -v $PWD:/app himax-build /bin/bash -c "cd build && cmake .."
    ```

1. And build and link the application:

    ```
    $ docker run --rm -it -v $PWD:/app:delegated -e SNPSLMD_LICENSE_FILE=27020@10.0.58.32 himax-build /bin/bash -c "cd build && make -j && sh ../make-image.sh"
    ```

## Flashing

You'll need to flash the `image_gen_linux_v3/out.img` file to the board using the XMODEM protocol.

1. Connect to the device on baud rate 115,200.
1. Bring the device into bootloader mode by resetting (via the button on the device) and pressing a key on your keyboard within 0.3 seconds.
1. Press `1`.
1. On MacOS with Serial.app choose **File > Send file** and make sure to set XMODEM as the protocol.
1. On Linux you can use minicom, see the [instructions from Himax](https://github.com/HimaxWiseEyePlus/bsp_tflu/tree/master/HIMAX_WE1_EVB_user_guide#flash-image-update-at-linux-environment).
