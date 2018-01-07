#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P8 "$1"
else
        java P8
fi


make clean
