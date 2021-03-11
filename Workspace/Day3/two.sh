#!/bin/bash 

#while assigning value to variable do not use dollor
#no space before/after assign operator 
num1=101
num2=5
# -n : skip trailing new line 
echo -n "Unix is simple. "
echo "It need a "
# -e  to enable escape sequence
echo -e "Unix is very  \n user friendly"
# to access/read value of variable use $
echo "num1 value is $num1"
echo "num2 value is $num2"
# only integer arithmetic possible in shell 
# for expression use expr compulsort
expr $num1 + $num2 
# traditional syntax, use backquote `` to compute and store, command substitutation or command expansion  
# can use var=$(command) also 
result=`expr $num1 - $num2`
echo "sub is $result"


