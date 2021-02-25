#!/bin/bash
set -e

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

cd $SCRIPTPATH/build
rm -f ../image_gen_linux_v3/*.elf
rm -f ../image_gen_linux_v3/*.map
cp *.elf ../image_gen_linux_v3
cp *.map ../image_gen_linux_v3

cd $SCRIPTPATH/image_gen_linux_v3

PATH=$PATH:$PWD

if [ "$2" = "--no-esc" ];
then
    FORMAT=""
    END_FORMAT=""
else
    FORMAT="-e \033[1m"
    END_FORMAT="\033[0m"
fi

if [ "$1" = "GNU" ];
then
    echo $FORMAT"GNU Image Gen Tool"$END_FORMAT
    ./image_gen_gnu -e *.elf -o out.img
elif [ "$1" = "MW" ];
then
    echo $FORMAT"Metaware Image Gen Tool"$END_FORMAT
    ./image_gen -e *.elf -m *.map -o out.img
else
    echo "Invalid arguments. Usage: ./make-image.sh [ GNU | MW ]"
fi

rm *.elf
rm *.map
