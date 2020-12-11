# day1

1. OS
- it is a interface between user and hardware 
- core of OS is Core OS/Kernel : 
  * it doing minimul basic functionalities, like 
   - 1. Process management 
   - 2. file I/O managaement
   - 3. memory management
   - 4. CPU Scheduling 
   - 5. hardware abstraction
  * OS also does extra functionalities like 
   - 1. User interfacing
   - 2. Networking
   - 3. Protection and Security
  
2. Linux
- linux is inspired by unix ,which was designed by denis richtie and in 1970
- unix is based on
    * file control subsystem (I/O management) and 
    * process control sub system
- its  logan is : 
* **"file have spaces and process have lines "** 
 -  i.e everything is a file , examples of special files are
    + data file, directory,pipe,socket,links(shortcuts),
    + block devices , where 1 sector = 512 bytes,
    + char devices , byte by byte 
 - process   

- system calls : 
 + A system call is a way for programs to interact with the operating system.
 +  A computer program makes a system call when it makes a request to the operating system's kernel.
 +   System call provides the services of the operating system to the user programs via Application Program Interface(API) 

- software interrupts

## OS Learning

1. end users
 - commands

2. administrator 
 - installation
 - shell scripts

3. programmer
 - system calls

4. designer
 - OS Internals 



## Linux Shell

1. Shell takes input from terminal i.e from end user and runs system call i.e get them executed by kernel  and shows output on terminal 
 - terminal is the window we give input and get output ,
 - internally terminal has shell 
*  two types of shell 
- 1. GUI Shell
   + in windows: explorer.exe
   + Linux : GNOME or KDE
- 2. CLI Shell 
   + windows: cmd.exe, POWER shell  
   
   + in linux : first was bsh then changed to bash (<u>b</u>ourne <u>a</u>gain <u>sh</u>ell)
      + csh/tcsh
      + zsh
      + zsh
      + ksh --> Korn shell(unix)

2. LINUX folder structure 
- 
1. in boot 
- linux kernal name : vmlinuz
- linux boot loader : grub

2. in bin 
- executables/commands
3. in sbin 
- system commands(admin)
4. in lib 
- contains libraries (.so) and device drivers(.ko)
     +  where ko: kernel objects
5. usr
- contains all installed programs/softwares

6. etc
- contains hardware and software configuration files  of: system,application , hardware 
  + source.list

7. dev
- contains device files(char and block)

8. proc
- for monitoring /dynamic config
- kernel window

9. sys 
- for device drivermanagement 


10. tmp
- its temporary file system(auto lost when shutdown) 

11. mnt
- mount point (to see other file system)
- optional 
- can mount cp or hdd using mount command
 > sudo mount /dev/sdb1 /mnt
 - sbd : pendrive 
 - sda : pc storage 
 - to unmount it 
 > sudo umount /mnt

12. root
- directory for admin user (i.e root )
-  

13. home 
- contains all users data like 
 + sunbeam
 + root 
- if username is sunbeam ,then it home directory is
> /home/sunbeam 


14. The table below shows the section numbers of the manual followed by the types of pages they contain.

- 1.    User/ Executable programs or shell commands
- 2.    System calls (functions provided by the kernel)
- 3.    Library calls (functions within program libraries)
- 4.    Special files (usually found in /dev)
- 5.    File formats and conventions eg /etc/passwd
- 6.    Games
- 7.    Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7)
- 8.    System administration commands (usually only for root)
- 9.    Kernel routines [Non standard]

## Linux Commands: 

1. Linux version
>  uname -a

2. List commandds
```shell
terminal > ls -l
# size of directory
terminal > ls -l -h 
```
3. command to show  shell 
```bash
 >  ls /bin/*sh
 > /bin/bash  /bin/dash  /bin/rbash  /bin/sh  /bin/static-sh
```
4. to change shell [NOT RECOMMENDED]
> chsh
- i.e change shell 

5. check working shell
>  echo $SHELL

6. to check boot folder content
> ls /boot
7. to get kernel/cpu info
> cat /proc/cpuinfo

8. to create directory
-  path -- w.r.t current directory
> mkdir <directory-name>
- it does'nt start with '/'
  
- path with wr.t to absolute path, 
> mkdir /home/sunbeam/<directory-name>
- start with '/' : are absolute path

9. for Relative path, Special directories are 
- 1. . : current directory
   > ./a.out
- 2. .. : 
>
- 3.  : 
>


10. list contents of current directory
 > ls  
 e.g :
 >  ls /boot
 - list content of your home directory / long view 
 > ls -l ~
 + where -l --- long listing (detail view)
 + contains type, mode/permissions,links,user,   group, size,modified timestamp,name
 

11. to change directory
+ from absolute or relative path
 > cd  commands
 - as not start with '/', so relative
+ 
 
12. to remove empty empty directory
> rmdir <directory-path>
- to delete contents in directory
> rm -r dirpath
13. cat command to create and insert file content
> cat > <filename>.txt
eg:
```bash
 cat > fruits.txt
 mango 
 banana
 # use cltr + D to come out from writing
 ```
- to view content of the file
> cat <filename>.txt

14. copy given directory to a destination directory
> cp -r <src> <dest>

15. move file into given directory
 > mv <filename> <dirpath>
- also use for rename a fle 
 > mv -r <filename>.txt
- In linux file/directory starting with "." is hidden
- to see hidden files
 > ls -a 
- to see hidden file content 
 > cat .fruits.txt 
 
16. IO redirection  
```sh
> ls -l -a 
# output is shown on terminal 
 # now to save output in file 
> ls -l -a > out.txt
# output copied to file  

> cat out.txt 
# we can see output of ls 

# for sorting 
> sort 
nitin
amit 
sandeep
nitin
amit 
nitin
nitin
sandeep

## INPUT redirection
# input(stdin) is taken from file and output on terminal
>  sort < fruits.txt

## OUTPUT redirection
# read output from, a file and writing in another file
> sort <  fruit.txt > result.txt

# for revrse order sorting
> sort -r <   fruit.txt

## ERROR redirection 
# invalid option -x 
> sort -x <   fruit.txt

# error output is shown on terminal
# output is shown on terminal (stderr)



# number of standard 
#stdin = 0,
# stdout = 1,
# stderr = 3

# so to write error output
> sort -x 2> err.txt

```

17.to give one command output to other commands  
- for word count 
```bash
> wc

hello sunbeam
here
# Cltr + O 
      2       3      20
#   lines    words   charcters

# to give one command output to other commands
> ls -l | wc
#left command (ls -l) output is given as input to right command(wc)
```

## Lab commands
1. LinuxFileSystemStructure
our application of Tree Data structure

!['directory-structure'](LinuxFileSystemStructure.png)
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
>  rm -r <directory>/
>  rm -r <file-name>
# 
```

1. list command syntax
>   ls [OPTION]... [FILE]...
- where 
 + ... indicate : multiple arguments allowed 
 + FIle: IO file , if not given , takes pwd  

