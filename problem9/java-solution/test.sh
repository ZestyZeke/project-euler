#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P9 "$1"
else
        java P9
fi


make clean
