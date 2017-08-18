#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P4 "$1"
else
        java P4
fi


make clean
