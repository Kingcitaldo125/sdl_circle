#!/bin/bash

if [ ! -d ./build ];
then
    echo "No build directory exists."
    exit 1
fi

./build/main
exit 0
