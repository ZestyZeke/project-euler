#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p1 "$1"
else
        ./p1
fi


make clean
