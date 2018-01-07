#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P10 "$1"
else
        java P10
fi


make clean
