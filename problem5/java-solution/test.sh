#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P5 "$1"
else
        java P5
fi


make clean
