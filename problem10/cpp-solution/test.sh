#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p10 "$1"
else
        ./p10
fi


make clean
