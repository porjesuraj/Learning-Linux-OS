#!/bin/bash

echo "please enter the year "
read year

if [[ `expr $year % 4` -eq 0 && `expr $year % 100` -ne 0 || `expr $year % 400 ` -eq 0 ]] 
then 
    echo "$year is a leap year"
else
   echo "$year is not a year"
fi 

