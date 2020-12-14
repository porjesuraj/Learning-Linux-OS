#!/bin/bash

echo "please enter no to find factorial "
read no 
sum=1
for (( i=1; i < 10; i++ )) 
do 
sum=`expr $sum \* i `

done 

echo "factorial of $no = $sum"

