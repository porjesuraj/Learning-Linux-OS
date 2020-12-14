#!/bin/bash

# print no ofday  in a month 

echo -n "enter a month "
read month 
month=`echo "$month" | tr "A-Z" "a-z"`

case $month in 
1|jan|january) 
  echo "Jan has 31 days"
  ;;
2|feb|february) 
  echo "Feb has 28/29 days"
  ;;
*) 
  echo "dont know "
esac  
  
