#!/bin/bash

echo "arg1 : $1"

echo "arg2 : $2"

echo "arg3 : $3"
echo "arg4 : $4"

echo "arg5 : $5"
echo "arg6 : $6"
echo "arg7 : $7"
echo "arg8 : $8"
echo "arg9 : $9"
shift 9

echo "arg10 : $1"
echo "arg11 : $2"
echo "arg12 : $3"
echo "arg13 : $4"

# terminal > ./demo10.sh A B C D E F G H I J K L M N 

# args: $1, $2, ..., $9
# HERE $10 AS ARGUMENT NOT AALLOWED	
# 1 way then is SO USE loop
# 2 way , use shift command 
# shift n command 
#  shift "n" args to left (left "n" args are discarded)

