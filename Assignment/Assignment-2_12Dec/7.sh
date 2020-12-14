#!/bin/bash

echo "please enter number to check if no id positive or negitive"
read no

if [ $no -ge 0 ]
then 
    echo "$no is positive "
else
    echo "$no is negitive"
fi 

