#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p3 "$1"
else
        ./p3
fi


make clean
