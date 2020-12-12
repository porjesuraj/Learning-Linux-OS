#/bin/bash

#calculate area of rect

echo -n "enter length: "
read len

echo -n "enter breadth: "
read br 

area=`expr $len \* $br`

echo "area $area"

echo -n "enter radius : "
read rad

# for floating point calculation, use bc --> i.e basic calculator 
# with  we can also use scale , no do decimal points it should be  accurate
area=`echo "scale=4; 3.1415 * $rad * $rad"| bc`
echo "area of circle : $area"

