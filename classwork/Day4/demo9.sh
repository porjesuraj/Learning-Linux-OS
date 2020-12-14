#!/bin/bash

# addition of all numbers passed on args

# terminal > ./demo9.sh 1 2 3 4 5 
# $* ---> collection of args

sum=0

for num in $*
do 
  sum=`expr $sum + $num`
done 

echo "sum = $sum"

