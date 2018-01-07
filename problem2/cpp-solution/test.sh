#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p2 "$1"
else
        ./p2
fi


make clean
