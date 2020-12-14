#!/bin/bash

echo "please enter name of file/dir"
read name

if [ -f $name ]
then 
   echo "file size  "
   ls -s $name
elif [ -d $name ] 
then
  echo "directory content"
  ls 
else
   echo "wrong name "
fi

