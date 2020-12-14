#!/bin/bash

# write a function to substract two numbers
# here echo in function are used for taking result to buffer ,again use echo after function call to print res
function substract()
{
 res=`expr $1 - $2`
 echo "$res"
}

function multiply()
{
res=`expr $1 \* $2`
echo "$res"

}

echo -n "enter two numbers"
read num1 num2 
result=$(substract $num1 $num2)
echo "result : $result"

multiply $num1 $num2

