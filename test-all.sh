#!/bin/bash

# bash script to test all scripts

for i in `seq 1 16`;
do
        cd "problem$i"
        ./compare
        cd ..
done
