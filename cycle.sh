#!/bin/bash
for (( i=3; i <= 10; i++ ))
do
  ./generator --big-superposition > file$i
#  ./lem-in < file$i | grep "$example" > FILE_FOR_GREP
#  if grep "segmentation fault " < FILE_FOR_GREP
#  then
#    echo "good"
#    echo $i
#  fi
done