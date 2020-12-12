# DAC_KDAC_FEB-2020: Linux Commands

## Excercise 1:

## Sachin Sir - day-lab1 
```bash

# 1.  to clear screen 
> clear
# or use Cltr + L 

# 2. to change dir to home directory 
> cd ~
# 3. to show current working dir
> pwd

# 4. create a  directory and a sub directory,  
# where -p: 
>   mkdir -p  os/linux_commands

# 5.changing directory 
  # - from inner directory to outer
  # use '..' + outer directory
  > cd ../../..

  # to go to root dir 
  > cd /
  # to go to the previous dir
  > cd - 
  # stay in current dir
  > cd .
  # go to parent dir
  > cd .. 

# 6. list commands 
     # list content/file names in dir
     > ls
     # list  content/file with hidden, and total data block allocated
     > ls -l -a
     
     # shows file/content info
     # drwxr-xr-x 3 sunbeam sunbeam 4096 Dec 11 14:51 ..
     # contians : 1)type-of-file :--> d: directory, -: for regular -
     #      2) wxr: are read and write permission
     # -l : to be displayed as a list
     > ls -l
     
     # here -s: show no of data block got allocated
     > ls -l -s
     
 

# 7 to make multiple  subdirectory in a dir
     > mkdir /one /two /three /four 
     
     # make sub directories recursivly
     > mkdir -p four/five/six
     # use :  -R to display list sub-directory recursively
     > ls -R four/

# 8 . cat commands 
  # to create and isnert in a file 
   > cat > file1.txt
    suraj
    raj
    ram
    # use Cltr + D
     
   #  to show the file 
   > cat file1.txt

   # now if we use same cat command , content get overwritten
   > cat > file1.txt

   #to display in reverse order
   > tac > file1.txt

   #concat multiple files
   >  cat file2.txt file3.txt

# 9 to delete a file or a directory 
>  rm -r <directory>
>  rm -r <file-name>
```




### Exercise:2
1. list directory contents of the dir five from cur directory (i.e. from home dir)
> ls dac/OS/OS-module/Assignment/one/two/three/four/

2. write your name in a file named 444.txt of dir four from current dir.
>  cd dac/OS/OS-module/Assignment/one/two/three/four/
> cat > 444.txt
> > cat 444.txt

3. remove the file named 555.txt from current directory.
> cd five
> rm -r 555.txt
4. change directory to five, use relative path to go dir five
>  cd dac/OS/OS-module/Assignment/one/two/three/four/five
5. write your course name in file named 333.txt which resides in dir three
>  cat > 333.txt
> cat 333.txt

6. list the contents of dir two from the cur directory (i.e. from five)
> ls ./../../..
7. remove file named 222.txt which belongs to dir two from cur dir.
> rm -r ./../../../222.txt
8. change directory to one
>cd ./../../../..
9. remove all the files only from dir named five from current directory (i.e. from one).
>  rm -r ./two/three/four/five
10. remove directory named five from the current directory (i.e. from one).
>  rm -r ./two/three/four/five
11. remove whole directory four from current directory (i.e. from one).
12. > rm -r  ./two/three/four/*
13. change directory to home directory
> cd ~
14. change the time stamps of the file named 333.txt which resides in a directory by
the name three from the current directory.
> touch ./dac/OS/OS-module/Assignment/one/two/three/333.txt
14. add contents into the file 11.txt by using cat command, and display again from
current directory (i.e. from home directory).
>  cat >  ./dac/OS/OS-module/Assignment/one/11.txt
>  cat   ./dac/OS/OS-module/Assignment/one/11.txt
15. append contenst inside the same file again from the same location.
> cat >>  ./dac/OS/OS-module/Assignment/one/11.txt
16. goto dir one, create a file by the name .india.txt and append data into it.
>  cat  >> ./dac/OS/OS-module/Assignment/one/india.txt
After creating file give $ls command & $ls -a command and check the difference.
> ls   ./dac/OS/OS-module/Assignment/one/
> ls  -a ./dac/OS/OS-module/Assignment/one/

17. displays calender of current month
```bash
> cal <year> :
#displays calender of year mentioned
> cal <month> <year> : displays calender of month of year
> cal -3

# display previous, current & next month calender
> cal -1

#displays calender of current month only.
# Command name: date
> date
# displays current date

```


## sachin sir - day-lab2

```bash
# copy all text files to destination 
# * : used to describe as all, if used with extension so all files of that type 
> cp ./*.txt ./../../../../
# using pipe to give output to 2nd command after | 
> cat 5.txt | less
#  Sort based on ASCII value
> > sort  numbers.txt | less

# to sort number in file numerically
> sort -n  numbers.txt | less

# sorter and unique 
> sort -n   numbers.txt | uniq

# head print 10 lines by default , we can set no of lines
> cat numbers.txt | head  -<number of lines>
> cat numbers.txt | head  -2

# tail to print from  last
>  cat numbers.txt | tail -<number of lines>

# can use tail and head together , pass one output as input to other
> cat numbers.txt | tail -15| head -5

#  -d : delimeter on basis on which it cut 
# -f1: prints 1st field 
> cat sunbeam.txt | cut -d " " -f1
> cat sunbeam.txt | cut -d " " -f2

# -i:display inode no 
> ls -i -l

# we can cut any list , and give which fields , like f1,f2
> ls -i -l | cut -d " " -f1,

# path of binary
> echo $PATH 

# tr : commands translates from one char to another
> echo $PATH | tr ":" "\n"

# tr : translates all small case into capital 
>  echo "Suraj" | tr "a-z" "A-Z"

> echo "Suraj" | tr "a-zA-Z" "A-Za-z"
- sUraj from Suraj


# chmod use for change permission , where u: user,g: group , o: other
# where w: write, r: read,x: execute 
# using u+x , u-x, we can change permission
> chmod g+w india.txt 
> chmod u+rwx india.txt 
> chmod o-rwx india.txt 
> chmod g-rwx india.txt 

# r: apply ls command
# w: we can create files and sub directory
# x: we can apply cd command on it 

# there are two formats/method by which we can change mode bits of a file i.e 
# we can assign /remove access permission : 
# 1. human readable : r,w,x 
 used as 
> chmod +rwx filepath
> chmod -rwx filepath

# 2. octal formats : 
# read : 4, write : 2, execute : 1
# first digit : octal digit start with zero , so lading 0 indicate octal contant
# second digit : access permission for user/owner
# third digit : access permission for group members
# fourth digit : access permission for other members
> chmod 0641


# create a alias for command , it is for  session 
> ls -l -a -i -s
# alias command: where l = alias
> alias l="ls -l -a -i -s"
# execute alias l 
> l
# command to remove alias 
> unalias l
```

