#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P2 "$1"
else
        java P2
fi


make clean
