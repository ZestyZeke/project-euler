#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P7 "$1"
else
        java P7
fi


make clean
