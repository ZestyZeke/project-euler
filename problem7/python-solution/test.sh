#!/bin/bash

if [ $# -eq 1 ]
then
        python3 p7.py "$1"
else
        python3 p7.py
fi
