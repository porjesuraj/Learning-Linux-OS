#!/bin/bash

echo "please enter three number to check for greatest"
read one 
read two 
read three

if [[ $one -gt $two && $one -gt $three ]] 
then 
     echo "$one is  greatest" 
elif [[ $two -gt $three && $two -gt $one ]]
then
     echo "$two is greatest "
else
     echo " $three is greatest"
fi 	
	

