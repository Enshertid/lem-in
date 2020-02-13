#!/bin/bash
ARG=$(./generator --big-superposition | ./lem-in | grep "[L#]")
echo $ARG | grep L | wc -l
#echo $ARG | grep -m 1 "#H"
