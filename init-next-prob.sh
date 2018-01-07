#!/bin/bash

# Script for setting up directory for next problem.

if [ $# -ne 1 ]; then
	printf "Usage: ./init-next-prob.sh <next-prob-#>\n"
	exit
fi

prev_prob="problem"$(($1 - 1))
next_prob="problem"$1

# delete directories (if existing, for debugging)
rm -rf "$next_prob"/c-solution
rm -rf "$next_prob"/cpp-solution
rm -rf "$next_prob"/java-solution
rm -rf "$next_prob"/python-solution

# make directories
mkdir "$next_prob"/c-solution
mkdir "$next_prob"/cpp-solution
mkdir "$next_prob"/java-solution
mkdir "$next_prob"/python-solution

# copy over files
cp "$prev_prob"/c-solution/Makefile "$next_prob"/c-solution/
cp "$prev_prob"/c-solution/test.sh "$next_prob"/c-solution/

cp "$prev_prob"/cpp-solution/Makefile "$next_prob"/cpp-solution/
cp "$prev_prob"/cpp-solution/test.sh "$next_prob"/cpp-solution/

cp "$prev_prob"/java-solution/Makefile "$next_prob"/java-solution/
cp "$prev_prob"/java-solution/test.sh "$next_prob"/java-solution/

cp "$prev_prob"/python-solution/test.sh "$next_prob"/python-solution/

cp "$prev_prob"/compare-times.sh "$next_prob"/

# modify files
c_prev="p"$(($1 - 1))
c_next="p"$1

sed -i.bak "s/$c_prev/$c_next/" "$next_prob"/c-solution/Makefile
sed -i.bak "s/$c_prev/$c_next/" "$next_prob"/c-solution/test.sh

sed -i.bak "s/$c_prev/$c_next/" "$next_prob"/cpp-solution/Makefile
sed -i.bak "s/$c_prev/$c_next/" "$next_prob"/cpp-solution/test.sh

sed -i.bak "s/$c_prev/$c_next/" "$next_prob"/python-solution/test.sh

java_prev="P"$(($1 - 1))
java_next="P"$1

sed -i.bak "s/$java_prev/$java_next/" "$next_prob"/java-solution/Makefile
sed -i.bak "s/$java_prev/$java_next/" "$next_prob"/java-solution/test.sh

# delete .bak files
rm "$next_prob"/c-solution/*.bak
rm "$next_prob"/cpp-solution/*.bak
rm "$next_prob"/java-solution/*.bak
rm "$next_prob"/python-solution/*.bak
