#!/bin/bash

# print all executable  files from given directory

echo -n "enter dir path : "
read dirpath 

if [ -d $dirpath ]
then 
  for file in `ls $dirpath`
  do
    if [ -x $file ]
	then 
	    echo "$file"
	fi
  done	
else 
   echo "invalid dir path"
fi 



