#!/bin/bash

str1='sunbeam'
str2='infotech'

str="$str1$str2"

echo "cat string : $str"

echo "string length : ${#str} "

echo "substring of a string "
# substring ffrom index 3 to last char
echo "${str:3}"
# substring from index 7 to next 4 char
echo "${str:7:4}"

echo "compare strings " 

if [ $str1 = $str2 ]
 then 
    echo "equal strings"
else
   echo "two strings not equal"
fi 

echo -n "enter phone number : "
read phone
# instead of regex we can use ready made syntax to  validate phone no 
if [[ $phone =~ ^[0-9]{10}$ ]]
then
    echo "valid phone no : $phone"
else
    echo "invalid no "
fi 	

# find and replace 
newstr=${str/tech/com}
echo "new string : $newstr "

