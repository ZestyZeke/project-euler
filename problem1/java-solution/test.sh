#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P1 "$1"
else
        java P1
fi


make clean
