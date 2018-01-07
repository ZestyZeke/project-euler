#!/bin/bash

# bash script to test all script solutions

for i in `seq 1 16`;
do
        cd "problem$i"
        ./compare-times.sh
        cd ..
done
