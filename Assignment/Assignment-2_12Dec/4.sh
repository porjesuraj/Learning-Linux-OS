#!/bin/bash

echo "please enter the number "
read no 

check=`expr $no % 2`

if [ $check -eq 0 ]
then 
   echo "$no is prime no"
else
    echo "#no is not a prime no"
fi 


