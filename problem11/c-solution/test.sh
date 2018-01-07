#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p11 "$1"
else
        ./p11
fi


make clean
