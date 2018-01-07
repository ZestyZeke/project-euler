#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p8 "$1"
else
        ./p8
fi


make clean
