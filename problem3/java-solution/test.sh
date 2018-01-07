#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P3 "$1"
else
        java P3
fi


make clean
