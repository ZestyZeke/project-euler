#!/bin/bash

if [ $# -eq 1 ]
then
        python3 p4.py "$1"
else
        python3 p4.py
fi
