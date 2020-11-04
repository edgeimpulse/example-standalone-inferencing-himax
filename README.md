# example-standalone-inferencing-himax
Builds and runs an exported impulse locally


## Setup
This project uses Cmake to generate the makefiles. 

## Build
Build the project using make

## Flash
An image is send over serial using the xmodem protocol. To generate the image run:
```make image```

The image is then stored in the `image_gen_linux_v3/' folder.
A HiMax example on flashing using Minicom can be found [here](https://github.com/HimaxWiseEyePlus/bsp_tflu/tree/master/HIMAX_WE1_EVB_user_guide#flash-image-update-at-linux-environment).
