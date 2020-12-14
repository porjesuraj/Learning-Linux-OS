#!/bin/bash

choice=1

while [ $choice -ne 0 ]
do 
echo “ Enter choice /n 1. Date, 2. Cal, 3. Ls, 4. Pwd, 5 or 0.  Exit”
read choice

case $choice in 

1) 
  date
  ;; 
2) 
  cal 
  ;;
3) 
  ls 
  ;; 
4) 
  pwd
  ;;
5) 
  exit 
  ;;
*) 
  echo "wrong choice" 
esac  
done 
