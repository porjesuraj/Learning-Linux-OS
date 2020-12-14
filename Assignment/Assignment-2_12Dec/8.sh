#!/bin/bash

echo "please enter no to print its table"
read no

count=1

echo "table of $no"
for (( $count; count < 11; count++ )) 
do 
result=`expr $no \* $count`
echo " $no * $count = $result  "

done
