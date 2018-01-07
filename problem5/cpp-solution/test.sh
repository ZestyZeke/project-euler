#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p5 "$1"
else
        ./p5
fi


make clean
