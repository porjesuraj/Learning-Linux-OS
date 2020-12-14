## Excercise 

```bash
# show name len = 255 , max 
> stat -f Assignment-2.md 
  #File: "Assignment-2.md"
  #ID: a563fc26170ea7a7 Namelen: 255     Type: ext2/ext3

# command to change shell 
> chsh 

```
1. Write a shell script to display your LOGIN NAME and HOME directory.
2. Write a shell script to display menu like “1. Date, 2. Cal, 3. Ls, 4. Pwd, 5. Exit” and
execute the commands depending on user choice.
3. Write a shell script to accept the name from the user and check whether user entered
name is file or directory. If name is file display its size and if it is directory display its
contents.
4. Write a shell script to determine whether a given number is prime or not
5. Write a Program to find the greatest of three numbers
6. Write a Program to find whether a given year is a leap year or not
7. Write a Program to find whether a given number is positive or negative
8. Write a program to print the table of a given number.
9. Write a program to find the factorial of given number.
10. Write a program to find given number of terms in the Fibonacci series.
11. Write a program to calculate gross salary if the DA is 40%, HRA is 20% of basic salary.
Accept basic salary form user and display gross salary (Result can be floating point
value).
12. Write a shell script to accept a filename as argument and displays the last modification
time if the file exists and a suitable message if it doesn’t exist.
13. Write a shell script to display only hidden file of current directory.
14. Write a shell script to display only executable files of current directory.
15. Accept the two file names from user and append the contents in reverse case of first file
into second file.
16. Write a shell script to display welcome message to the user along with contents of his
home directory. Ensure that shell script will execute automatically when user login to the
shell. (Make entry of your shell script into .bashrc file into your home directory).
17. Print the following pattern.
*
* *
* * *
* * * *
* * * * *

- test command manual

```bash

      
       ( EXPRESSION )
              EXPRESSION is true

       ! EXPRESSION
              EXPRESSION is false

       EXPRESSION1 -a EXPRESSION2
              both EXPRESSION1 and EXPRESSION2 are true

       EXPRESSION1 -o EXPRESSION2
              either EXPRESSION1 or EXPRESSION2 is true

       -n STRING
              the length of STRING is nonzero

       STRING equivalent to -n STRING

       -z STRING
              the length of STRING is zero

       STRING1 = STRING2
              the strings are equal

       STRING1 != STRING2
              the strings are not equal

       INTEGER1 -eq INTEGER2
              INTEGER1 is equal to INTEGER2

       INTEGER1 -ge INTEGER2
              INTEGER1 is greater than or equal to INTEGER2

       INTEGER1 -gt INTEGER2
              INTEGER1 is greater than INTEGER2

       INTEGER1 -le INTEGER2
              INTEGER1 is less than or equal to INTEGER2

 INTEGER1 -lt INTEGER2
              INTEGER1 is less than INTEGER2

       INTEGER1 -ne INTEGER2
              INTEGER1 is not equal to INTEGER2

       FILE1 -ef FILE2
              FILE1 and FILE2 have the same device and inode numbers

       FILE1 -nt FILE2
              FILE1 is newer (modification date) than FILE2

       FILE1 -ot FILE2
              FILE1 is older than FILE2

       -b FILE
              FILE exists and is block special

       -c FILE
              FILE exists and is character special

       -d FILE
              FILE exists and is a directory

       -e FILE
              FILE exists

       -f FILE
              FILE exists and is a regular file

       -g FILE
              FILE exists and is set-group-ID

       -G FILE
              FILE exists and is owned by the effective group ID
-h FILE
              FILE exists and is a symbolic link (same as -L)

       -k FILE
              FILE exists and has its sticky bit set

       -L FILE
              FILE exists and is a symbolic link (same as -h)

       -O FILE
              FILE exists and is owned by the effective user ID

       -p FILE
              FILE exists and is a named pipe

       -r FILE
              FILE exists and read permission is granted

       -s FILE
              FILE exists and has a size greater than zero

       -S FILE
              FILE exists and is a socket

       -t FD  file descriptor FD is opened on a terminal

       -u FILE
              FILE exists and its set-user-ID bit is set

       -w FILE
              FILE exists and write permission is granted

       -x FILE
              FILE exists and execute (or search) permission is granted

```