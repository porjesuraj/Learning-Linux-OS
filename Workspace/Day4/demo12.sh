#!/bin/bash

# array demo

declare -a arr		# optional array declaration
arr=(11 22 33 44 55)

echo "element 0: ${arr[0]}"
echo "element 1: ${arr[1]}"
echo "element 2: ${arr[2]}"
echo "element 3: ${arr[3]}"

echo "array element count: ${#arr[*]}"

for num in ${arr[*]}
do
	echo "in for loop - ele: $num"
done

i=0
while [ $i -lt ${#arr[*]} ]
do
	echo "in while loop - ele: ${arr[$i]}"
	i=`expr $i + 1`
done


            
