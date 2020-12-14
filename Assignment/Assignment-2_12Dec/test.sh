#!/bin/bash

clear 

i=1 
while [ $i -le 5 ] 
do 

j=1
while [ $j -le 5 ] 
do 
echo -e  -n "\t[$i ,  $j]"

j=`expr $j + 1`
done
echo ""
i=`expr $i + 1`


done 

