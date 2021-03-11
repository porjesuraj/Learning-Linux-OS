#!bin/bash

# print table of given number

echo -n "enter a num: "
read num 

i=1

while [ $i -le 10 ] 
do 
  res=`expr $num \* $i` 
  echo "$res"
  i=`expr $i + 1`
done

for (( i=1; i<=10; i++ ))
do
  res=`expr $num \* $i`
  echo "$res"
done  
