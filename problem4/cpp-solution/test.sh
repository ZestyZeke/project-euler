#!/bin/bash

make

if [ $# -eq 1 ]
then
        ./p4 "$1"
else
        ./p4
fi


make clean
