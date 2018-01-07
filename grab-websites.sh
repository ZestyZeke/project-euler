#!/bin/bash

# Script to grab the websites from each Project Euler problem

for i in `seq 3 16`;
do
        mkdir "problem$i"
        cd "problem$i"
        wget "https://projecteuler.net/problem=$i"
        cd ..
done
