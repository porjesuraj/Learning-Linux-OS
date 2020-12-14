#!/bin/bash
# shebang line 

# addition of two numbers --passed on command line 

if [ $# -ne 2 ]
then 
    echo "invalid argu"
	exit 
fi 

result=`expr $1 + $2`
echo "result : $result"





# terminal> chmod +x demo8.sh 
# terminal> ./demo8.sh 11 33

#$0 ---> name of script --> demo8.sh 
# $1 --> arg1 ---> 11
# $2 ---> arg2 ---> 333
# $3,...,$9

# $# ---> count of arguments ---> 2 arguments for this program 
# file name is excluded 

