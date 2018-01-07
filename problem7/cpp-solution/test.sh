#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p7 "$1"
else
        ./p7
fi


make clean
