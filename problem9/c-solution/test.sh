#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p9 "$1"
else
        ./p9
fi


make clean
