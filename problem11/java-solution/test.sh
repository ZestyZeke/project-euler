#!/bin/bash

make

if [ $# -eq 1 ]
then
        java P11 "$1"
else
        java P11
fi


make clean
