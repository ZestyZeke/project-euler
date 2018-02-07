#!/bin/bash

echo "this is total lines including git repos"
find ~/Documents/project-euler/ -type f -exec wc -l {} \; | awk '{total += $1} END{print total}'

echo "this is total lines of git repos"
find ~/Documents/project-euler/.git -type f -exec wc -l {} \; | awk '{tot += $1} END{print tot}'
