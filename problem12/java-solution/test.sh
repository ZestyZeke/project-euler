#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P12 "$1"
else
        java P12
fi


make clean
