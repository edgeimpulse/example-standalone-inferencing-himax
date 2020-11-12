#!/bin/bash
set -e

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

cd $SCRIPTPATH/build
cp edge-impulse-standalone-himax.elf ../image_gen_linux_v3
cp edge-impulse-standalone-himax.map ../image_gen_linux_v3

cd $SCRIPTPATH/image_gen_linux_v3

PATH=$PATH:$PWD

./image_gen -e edge-impulse-standalone-himax.elf -m edge-impulse-standalone-himax.map -o out.img
rm edge-impulse-standalone-himax.elf
rm edge-impulse-standalone-himax.map
