#!/bin/bash

file="compare-times.txt"
[ -e $file ] && rm $file

printf "This is the C solution time:\n" >> $file 
cd c-solution && (time ./test.sh) 2>> ../$file && cd ..

printf "This is the C++ solution time:\n" >> $file
cd cpp-solution && (time ./test.sh) 2>> ../$file && cd ..

printf "This is the java solution time:\n" >> $file
cd java-solution && (time ./test.sh) 2>> ../$file && cd ..

printf "This is the python solution time:\n" >> $file
cd python-solution && (time ./test.sh) 2>> ../$file && cd ..
