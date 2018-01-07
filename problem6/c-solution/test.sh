#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p6 "$1"
else
        ./p6
fi


make clean
