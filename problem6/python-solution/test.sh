#!/bin/bash

if [ $# -eq 1 ]
then
        python3 p6.py "$1"
else
        python3 p6.py
fi
