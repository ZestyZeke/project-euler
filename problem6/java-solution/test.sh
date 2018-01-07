#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P6 "$1"
else
        java P6
fi


make clean
