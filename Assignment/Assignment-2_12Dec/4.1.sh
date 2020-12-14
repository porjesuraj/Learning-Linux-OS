#!/bin/bash

echo "please enter the number "
read no 

flag=0
i=2

while [ $i -ne $no ]
do
if [ `expr $no % $i` -eq 0 ] 
then 
    flag=1
fi
i=`expr $i + 1`
done

if [ $no -eq 1 ]
then 
    echo "1 is neither prime or composite"
elif [ $flag == 0 ]
then 
    echo "$no is  prime no"
else
   echo "$no is not a prime no"
fi 


