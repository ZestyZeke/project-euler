#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p12 "$1"
else
        ./p12
fi


make clean
