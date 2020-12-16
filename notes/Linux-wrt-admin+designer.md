# syllbus
* Linux Commands,
*  Vi editor, 
*  Shell Scripting,
*  Overview of OS,
*  Processes,
*  Scheduling & Synchronization,
*  Memory management, 
*  File Systems,
*  Case Study with Linux System Programming: Process, 
*  Signals,
*  Semaphores & Mutex, 
*  Inter – Process Communication, POSIX Threads

### NOte
1.  linux supportedfile system manager : (its own)ext3,fat,cdfs,ntfs
2.  windows supported system manager : fat,Ntfs,cdfs 
3.  if you want to see liux file system  in windows , use linux reader, ext2Fsd application 

# day4 : OS -FIle System 

## FILE  System 
1. file is collection of data and information on storage device 
*  i.e file = data(content) + metadata(information about file)
- 1.   metadata is stored in inode (FCB)  (FIle Control BLock)
  *  contain Type,Mode,Size,User and Group,Links
  * Timestamps ,info about data blocks
  - where inode is structure 
  - we can view metadata using, where filepath can be directory/file  
  > stat filepath  
- 2. File data is stored in 
  *  we have 3 types of file stytem : NTFS,FAT,ext3 
  * where  file system is the way of organizing file in disk
2. **File System is divided in 4 blocks** ,which are
- 1. **Boot block/Sector**
  *  contains bootstap laoder 
  *  GRUB (grand unified bootLoader) for linux 
- 2. **super block / Volume Control Block**
  * it contains  info about partition, i.e remaining sections,
  * it contains metadata, 
  * total no of data block present in disk space(data block) is done in super block 
    + no of free data blocks
    + no used data blocks
  * there are four methos/ways by which information about free dta blocks can be kept inside super nblock referred as "free space management mechanism" 
  + 1. bit vector
  + 2. liked list
  + 3. counting 
  + 4. grouping   
  * like label of storage, storage info , used, free space
       
- 3. **inode list block/ Master File Table**
  * inode structure , view using inode command
   * it contains pointer for  each files in  data block
   * even for empty file inode is there   
- 4. **Data blocks**
   *  file data 
* this is general form for file system, no necessary for all file system to be same 
* way of organizing file in filesystem changs FS to FS   
* 


3. FIle System Architecture
+ 1. diagram 
!['File-system-arch']()
+ 2.  some  System Call API are 
 + 1. open ()
 + 2. close () 
 + 3. read ()
 + 4. write()
 + 5. lseek()
 * called by system so called system calls 
+ 3.   
#### mcq on system call, output type 


4. demo on system call API  
- 1. to copy a file content to another file 
```c++
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, fs;
	char buf[32];
	int cnt;

	//0. check number of command line args

	if(argc != 3) {
		printf("invalid arguments.\n");
		return 1;
	}

	//1. open source file for reading
	fs = open(argv[1], O_RDONLY);
	if(fs < 0) {
		perror("open() failed to open source file");
		_exit(1);
	}
	//2. open destination file for writing
	fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if(fd < 0) {
		perror("open() failed to open destination file");
		_exit(1);	
	}
	//3. read few bytes from source file
	while( (cnt = read(fs, buf, sizeof(buf))) > 0 )
	{
		//4. write those bytes into destination file
		write(fd, buf, cnt);
	} //5. repeat steps 3 & 4 until end of source file

	//6. close destination file
	close(fd);
	//7. close source file
	close(fs);
	printf("file copied.\n");
	return 0;
}
//terminal> gcc -o filecopy.out filecopy.c
//terminal> ./filecopy.out ~/.bashrc copy.txt          
```
- now command to compile and run file 
```bsh
terminal> gcc -o filecopy.out filecopy.c
terminal> ./filecopy.out ~/.bashrc copy.txt
```
- 1. **FILE POSITION pointer (f_pos)** 
* file position is a pointer maintained for each file
* it  is zero/start when we  open a file
* so when a read/write happens, file position moves by that many bytes(eg 32 bytes)
* for each successive read/write, till the last byte of file, now 
file position becomes zero (0)

- 2.Why OS is written in C,C++, and Assemby language? 
  * Linux/Unix is written in C language
  * 3 choices to write OS , C,C++ and Assembly langauge, as they are Hardware oriented language  
  * Window written in C and C++


- 3. Directory
 * in windows called folder and linux called directory
 * internally it is a file, 
 * that contains directory entries for each syb directory and file in it
 *  4096 byte(4kb) make a one data block, i.e its size
 *  let take a example as /home/sunbeam/.bashrc
 1. sunbeam is a directory , it it also a special file , with inode and data block
 -  each file has a inode and data block 
 -  so we want to open the directory /home/sunbeam/.bashrc
  + here we firs t look in '/' and find home, and then its indoe is taken based on which it goes to home , and search in its data block sunbeam, similary takes sunbeam inode and goes to its data block and find .bashrc  takes it s inode no, use it to open file     
 2. 
 - 1. for each process there is a process control block (PCB), it maintains a table called OFDT  
 - converting  path name to inode number is called namei()
 - 2. so there is a inode table in OS, as if no table, it will be slow to access inode each  table, it contains/load inode no i.e for each file , size,Type
 - 3. to access it/ open a file , it  have a table, open file table(OFT), contains entry of  inode table here to file
   + it contains pointer to file, f_pos=0,
 - 4.  open file descriptor table (OFDT) contains pointer/address to OFT ,also  index  of OFTD to the program called as File discriptor
 
 ### terms 
 - 5. here struct inode : inode tableentry
 - 6. struct file : OFT entry
 - 7. data block size (DBS) :
    - it is the memory block each file contains, with inode , i.e given to OS on creation
    -   its default size, can be seen in format option 
    -   it is by default 4096 bytes (4kb)
    - it means , so we can set it i.e data block for file,
    -  so 4kb in minimum/default size of data block size for each file  
    - so this is a minimum no of bytes each file occupy 
    - so higher the DBS , faster execution , but higher is wastage of space 
    - size of buffer in buffer cache = size of Data block
  
  - 8. so for each swp file , new inode is created, whenwe open a file in Vim editor 
  - 9. on harddisk level, write operation is done on sector basis i.e 512 bytes, it is called physical block size 
  - 10. for each file Data block is called it file level or logical block size
  - 9.  
    > #pragma pack1 
    - related to OS and hardware , not data block
   

1. commands to check 
- memory info 
> free -mh
- cpu info
> lscpu


# day 5


1. a file has boot block,super block, inode block, data block
2. so file logical 1st block mapping to harddisk block , this info is kept in inode
3. as inode contains info about data block, using which we can access respective block 
4. VFS (Virtual File System) ---> file ---> called flat files (i.e shown as contiguous memory file)
+   VFS convert file logical block to disk block using data blocks info in inode
5. to change current file position 
> newpos = lseek(fd,offset,whence)
+ where  fd: file discriptor, offset:  , whence : origin (values can be 0 (SEEK_SET),1(SEEK_CUR),2(SEEK_END) )
+ in c we have 
 > fseek(fp,offset,whence)
6. e.g **MCQ IN EXAM**
- 
0. lseek return new file position  from beginning of the file 
1. > lseek(fd,0,SEEK_SET)
+ take f_pos to start of file
+ in c library to do this, rewind(fp) 
2.  >lseek (fd,0,SEEK_END);
+ takes f_pos to end of file 
+ here lseek returns file size , as goes to last bite
3. lseek(fd,0,SEEK_CUR);
+ its stays in current position, so f_pos doesnt change
+ it will return current file position 
+ same as C function, ftell()

7. f_pos is kept in OFT (Open File Table)
+ if file open 4 times , then 4 time access OFT ,and have 4 f_pos 

8. FIle I/O System Calls
+ open()    ---- fopen() --- returns FIle* 
+ close()  ----  fclose() 
+ read()  ----  fread()
+ write()  ---- fwrite()
+ lseek()  ---- fseek()

9. if dealing with Directory 
> man 3 readdir
- 1. openat()  --- opendir()   --- return DIR*     
   + to read directory 
- 2. getdents() ---- readdir()
  + get directory
- 3. close() --- closedir()
  + close directory

- people prefer using library functon ,not syste mcall
-      

10. file sywstem commands  
+ 1. mkdir()
+ 2. stat()
+ 3. rm cmd --> unlink() 
+ mv cmd --> link and unlink command 


11. **Links in linux (shortcuts)**
* two types of link are there
1. Hard Link (another name for file)
 + another directory entry pointing/ referring to same inode 
```sh
> ln filepath linkpath

terminal> mkdir ~/links

terminal> cd ~/links

terminal> echo "first file." > one.txt

terminal> ls -l -i
## output  having link count 1 
##: 8535450 -rw-r--r-- 1 sunbeam sunbeam 11 Dec 15 09:28 one.txt
terminal> ln one.txt two.txt

terminal> ls -l -i

terminal> ln one.txt three.txt

terminal> ls -l -i

# we can see link count became 3 here 
8535450 -rw-r--r-- 3 sunbeam sunbeam 11 Dec 15 09:28 one.txt
8535450 -rw-r--r-- 3 sunbeam sunbeam 11 Dec 15 09:28 three.txt
8535450 -rw-r--r-- 3 sunbeam sunbeam 11 Dec 15 09:28 two.txt
```
- 1. link command
> ln filepath linkpath
*  ln command internally call link() system function
* as link dir has inode and data block 
*  internally given inode to all link  file, same as first file 
- 2.  rm command
> rm filepath
* internally makes call to unlink system call, it simply deletes directory entry, 
* it decrement link count , if link count becomes zero, then release inode and data block of file
* shown in the below code  
```bash
>  rm three.txt
>  ls -l -i
#output 
## 8535450 -rw-r--r-- 2 sunbeam sunbeam 11 Dec 15 09:28 one.txt
## 8535450 -rw-r--r-- 2 sunbeam sunbeam 11 Dec 15 09:28 two.txt
>  cat one.txt
first file
>  cat two.txt
first file
>  rm one.txt
>  cat two.txt
first file
>  ls -l -i
total 4
8535450 -rw-r--r-- 1 sunbeam sunbeam 11 Dec 15 09:28 two.txt
>  rm two.txt
>  ls -l -i
total 0
>  

```

* cannot create hardlink for directory
- 3. data recovery software,makes directory entry for your file deleted, so recovering data, 
   + its dependent on file system 
   +  here when we delete, inode entry of deleted entry removed, data still there for reuse, till we override data over that data block, then it is completely deleted
- 4. to completely delete a dile i.e non recoverable data , file recovere possible, 
   + for this,override and delete
   + there is shred command in linux for it , it garbage write file and delete it
   + so file can be recovered and data is garbage
- 5. to complete delete , with no file recoverable
  +  use format, can be recovered
  +  if use quick format, can be recovered
  + special utility software, zero utility format , completely 0 every file 

#### by default link count of directroy file is 2 ,
#### by default link count of file is 1 
        

* 2. ****
 + it is good practice to use absolute path of targeted file ,while creating symbolic link
 + same as windows shortcut
 +using link command, it creates a new special file , to keep addr/path of target file ,using
 > ln -s filepath linkpath 
  - internally calls , symlink () system call
+ here link count does not change  , linked file contains path for file, so has memory of 7(name of file n bytes) bytes for the address of target file  
+ if main file deleted, linked file becomes useless
+ here  we can differentiate between targeted and linked file as diffrent file created, different inode,and datablock  , not possible in hard link 
+ if targeted file(one.txt) is deleted, now other linked file becomes like dangling pointer , so no use for them, must be deleted 
```bash
>  echo "new first file" > one.txt
>  ls -l -i
## output
#8535450 -rw-r--r-- 1 sunbeam sunbeam 15 Dec 15 09:55 one.txt
>  ln -s one.txt two.txt
>  ls -l -i
## output
#8535450 -rw-r--r-- 1 sunbeam sunbeam 15 Dec 15 09:55 one.txt
# 8535451 lrwxrwxrwx 1 sunbeam sunbeam  7 Dec 15 09:56 two.txt -> one.txt
>  ln -s one.txt three.txt
>  ls -l -i
## output 
# 8535450 -rw-r--r-- 1 sunbeam sunbeam 15 Dec 15 09:55 one.txt
# 8535452 lrwxrwxrwx 1 sunbeam sunbeam  7 Dec 15 09:58 three.txt -> one.txt
# 8535451 lrwxrwxrwx 1 sunbeam sunbeam  7 Dec 15 09:56 two.txt -> one.txt
>  rm three.txt
>  ls -l -i
## output
# 8535450 -rw-r--r-- 1 sunbeam sunbeam 15 Dec 15 09:55 one.txt
# 8535451 lrwxrwxrwx 1 sunbeam sunbeam  7 Dec 15 09:56 two.txt -> one.txt
>  rm one.txt
>  cat two.txt
# cat: two.txt: No such file or directory
>  ls -l -i
#8535451 lrwxrwxrwx 1 sunbeam sunbeam 7 Dec 15 09:56 two.txt -> one.txt
>  rm two.txt
 
```


12. ### Free Space Management Mechanism
* when a file is requesting for free data blocks , then in which manner free data blocks get allocated for the file and in which  manner info about those alocated data block can be kept inside an inode of that file
* physical data block exist in "data block " called as disk space 
* total no of data block present in disk space(data block) metadata present  in super block  are 
    + no of free data blocks
    + no used data blocks
  * there are four methos/ways by which information about free dta blocks can be kept inside super nblock referred as "free space management mechanism" 
  + 1. **bit vector** : array of bits 
     + in this mechanism,in super block bit vector i.e array of bits get maintained having size = total no of data block present in a data block(disk space)
     + i.e if total no of dataa block = K 
     + size of bit vector = K 
     + each data block has address from 0 to (K-1)
     + if nth bit = 0 ---> nth data block is free
     + if nth bit = 1 ---> nth data block is used
     + when any file is requesting for free data blco under disk allocation method bit vecotr get scanned
     + this mechanism is used with either linked allocation or index allocation 
     + e.g : Extended filesystem  :LINUX 
  + 2. **liked list**
     + in this , linked list of free data blocks get maintained inside data block itself and adress of starting data block in that list can be kept inside a super block
     + this mechanism is used with linked and index allocation
     + e.g :FAT16/FAT32  
  + 3. **counting** 
     + in this mechanism , information about contiguous free data block can be kept in a super block
     + consist : 2 ---->  4 [count] (for block 2 to 5 contiguous free memory)
     * address of starting free data block  ---> count (no of free data blocks exits in a contiguous manner including starting data block)
     + this mechanism used with contiguous allocation 
  
  + 4. **grouping**
     + in this mechanism , group of contiguous free data blocks get maintained and addresses of data blocks i nthat group get stored into the first free data block i nthat group, and address of first group data block can be kept in super block.     





13.  ### Disk Allocation Mechanism 

* three popular mechanism : 
 1. **contiguous(C) allocation**
 + inode contains mapping of logical block in inode with hardisk physical block 
 * **limitation on growing of file**, as no contiguous memory available, even in memory is available on HDD
 * amount of memory  required for file is available but not contiguous this is called      **external /dis fragmentation** 
 + so moving disk block of HDD to make avaialable space contigous is called Defragmentation
 + as memory in C, we can do sequential and ramdom access of memory    


 2. **linked allocation**
 + to remove external fragmentation problem 
 + here each block contains data and pointer to next block, so memory for file is not contiguous 
 + inode contains mapping of logical block in inode with hardisk physical block(start block and end block )
 * so last block can be changed, as file grows 
 *  so here ramdom access is slow
 * eg : FAT system 

 3. **indexed allocation**
 + here, a special block is kept to maintain the information, i.e address of data blocks for a file, this block is called index block , this allocation is indexed allocation   
 * no extrnal fragmentation , but 
 * size of index block , has limitiation , so certain limitation for file to grow 
 * here we can do sequential and random access 
 * example in case of unix File System created by Dennis Richtie 
  + they have index box to keep data block  address, ]
  + here each index block has multiple entries and each entry is a index block , containing actual entries 
  + i.e index block pointing to multiple index block pinting to actual data block , 
  + here mx file allowed 16 GB, and block size = 4kb,   
  + model file system: Ext2/3 --> similar to UFS , having an array of 15 memeber, not 13 of UFS , to create max file size 100GB 
  + so index blocked  creating new index block in UFS , are called single indirect block, double indirect block ... ,
      - as no of indirect block increase ,speed decreases 
      - as small files faster access , larger file slower access   
  + used by Linux (ext3,ext2 )  

14. Journaling
+ file system work in progress, for bigger file , large time req, and power failure there, so system gets down , so previous operation , a journel / log file is maintained here ,and how work is done, file system maintains log of each activity, so when system reboot file system refer the log file, and file system corruption chances reduces .  

# day5 afternoon session 

1. to check storage
> sudo fdisk -l
2. bebug 
> sudo debugfs path 

3. free space management algorithm 
+ super block maintains info about free inode , free data block 
+ there are 4 algorith of free space management : 
* 1. bit vector/map 
  + 4kb size of bit vector 
  + 
* 2. linked list mechanism 
  + each free block contains address of next free block   
* 3. index mechanism 
  + start block contains address of all contiguous
* 4. counting 
   + no of free block are counted and listed

 4.   general  structure of ext2/ext3 
!['ext3/2-arch']()
 * 1.  create file system in linux
 > sudo mkfs -t ext3 /dev/sdb1 
 + for window file system creation use format command 

* 2.  ext3 in partition has a block group which contains 
  + 0. Boot block 
    + common for all blocks in one partition 
  + 1. super block
     + disk info
  + 2. group descriptor
     + current group info
  + 3. inode bit vector
  + 4. database bit vactor
  + 5. inode library
  + 6. data blocks

 5. ext3 = ext2  + journaling  
  * to avoid inconsistency ,so FS doesnt get corrupt, due to power failure, solution is journaling i.e logging of FS activities , and match them on power on 
  * for this use journal /log file,
  * for file system checks, we use tool 
  > fsck /dev/sdb1
    +  here check all directories,inode,and databases, this is slow proces
  * journalling speedup checks by limiting checks to currently operated files and directories 

  ### IMP for MCQ : 6
6. for Disk Management 
!['hdd-arch'](day5_hdd-arch.png)
* Disk access time = rotational latency + seek time
* when accessing disk , if following request are pendlng ,80,20,90,10,40,65,5
* my hdd arm pointer is at 30 , and radius from 0 to 100
* for this we have disk sheduling algorith
+ 1. **FCFS : first come first served**
  - follow same order of request order 
 * 30 -> 80 ->20 -> 90 -> 10 -> 40 -> 65 -> -> 35 
 + so total seek distanxce = 50 + 60 + ... = 395 
+ 2. **SSTF : Shortest Seek Time First** 
  - from current location of pointer , go to the nearest request
  * 30 -> 35 -> 40 -> 20 -> 10 -> 5 -> 65 -> 80 -> 
  + T.S.D  = 5 + 5 + 20 + ....= 130
+ 3. **Scan /Elevator Alorithm** 
  *  magnitec tip keep moving from 0 to max , and access request as they come 
  *  30 -> 35 -> 40 -> 65  -> 80 -> 90 -> 100 -> 90 -> ....->30-> 20 -> 10 ->5 
  + T.S>D = 
  * this algorithm is used in LINUX , by IO sub system 
+  4. **Circular SCAN** 
   * here magnetic pointer moves from  0 to max, then jumps back to 0 
   * 30 --> 35--> 40 --> 65 --> 80 --> 90 --> 100 ---> (back to 0) --> 5 --> 10 --> 20

+ 5. **Look Algorithm**
  * implementation policy of SCAN/C-SCCAN to conserve power /energy 
  * move as a SCAN or C-SCAN, only when request pending ,its implementation policy 


7. Process Management 
* galvin book chapter 3,4,5
1. Process is a program in execution 
2. 

3. OS data structures for process execution 

* 1. Job Queue / Process table/ Process List 
  + contains all processes(PCB) in system
* 2. Ready Queue/ Run Queue 
  + all processes ready to execute on cpu 
* 3. waiting queue(s)
  + waiting queue per device for per syncronization object
       
 
 #### synchronizing object in java used by synchronized keyword is : monitor

4. **Process Life/State Cycle (PLC)**
 * running process is PLC
- 1. JOB-QUeue (new process initialized here)
 *  starts at Job-Queue /New --> initialized then added to
- 2. Ready Queue
 *  (ready for execution process)
 * here cpu dispatch i.e (process goes from ready to running state) takes place  
- 3. Running queue 
 *  now CPU scheduler puts it in running state, it consumes time here, based on Round RObin algo
 * if interupt occur, process go back to ready state ,
- 5. Waiting Queue 
 *  if there is I/O operation / syncronization operation in Running state, process goes to waiting Queue (here P is sleeping)
- 6. once I/O operation finished, P go to Ready state, and then go to running 
- 7. now after running process get Terminated  


5. Linux Process State 
* they are 
- 1. **R state** 
  + mean (process is Ready or Running) 
  + indicated by (TASK_RUNNABLE) 
  + if process has i/o request or syncronization operation 

- 2. Linux(process waiting) has types
  * 1.**S state , its Interuptable sleep**
   + request not complete , but by sending signal, process  in wait can also forcebly awaken, by interrupt
   + it has macro  TASK+_INTERRUPTABLE  
  * 2. **D state its Un-Interruptaable sleep** : 
    + also refer as dormant state
    +  request not complete , but by sending signal, process  in wait cannot be forcebly awaken, by interrupt
    +   it has macro  TASK+_UNINTERRUPTABLE 
  * 3. process suspended 
    + process in stop state, using stop() signal(Cltr + S can be used for this in VIm and to awaken Cltr + Q ) 
    + macro TASK_STOPPED
- 3. **Z state(process terminated)**
   + here we use exit 
   + macro TASK_ZOMBIE  


6. commands to check state of process
> ps -e -o pid,state,cmd
* to let a process go to background , use Cltr + Z
  > bg
* to bring it back to foreground
> fg

7. CPU Scheduler
* decides next process to be executed on CPU 
8. CPU Dispatcher
* dispatch the process on CPU i.e load its execution context (CPU regualr values) into CPU 


7. Process Creation(PC) 
+ 1. PC depends on Operating System ,its system call 
 * example 
  + 1. in windows --> CreateProcess()
  + 2. in Unux --> fork()
  + 3. in BSD UNIX --> fork(), vfork()
  + 4. Linux ---> fork(),vfork(), clone()
+ 2. we are gonna use fork()
  
8.  **fork()**
* creates  a new process by duplicating the calling process.  The
new process is referred to as the child process.  The  calling  process
is referred to as the parent process.
* The child process and the parent process run in separate memory spaces.
*The child process is an exact duplicate of the  parent  process  except
for the following points:
*  The child has its own unique process ID, and this PID does not match
 the ID of any existing process group (setpgid(2)) or session.

+ On success, the PID of the child process is returned in the parent, and
 0  is returned in the child. 
 +  On failure, -1 is returned in the parent,
  no child process is created,

* 1. basic structure  
 ```c++ 
 #include <sys/types.h>
 #include <unistd.h>
// pid is type def on int
//   pid_t fork(void);

main(){

  int ret;
  ret = fork(); 
  // it successful, return 0 to child process and pid no to pCB and parent 

printf(); // run by parent and child
  if( ret == 0) {
    // true for child process
  } else{
    // true for parent 
  }

}

 ``` 

* 2. basic demo 
 ```c++
#include <stdio.h>
#include <unistd.h>

int main() {
	int ret;
	printf("program started.\n");
	ret = fork();
	printf("fork() returned: %d\n", ret);
	printf("program completed.\n");
	return 0;
}

// terminal> gcc -o fork.out fork1.c
// terminal> ./fork.out

 ```

- on bash 
```bash

> gcc -o fork-file1.out fork-file.c
> ./fork-file1.out 
program started.
fork() returned: 19890
program completed.
fork() returned: 0
```

3.  demo with different  tasks for parent and child process
* use to run process concurrently ,independent process  
```c++
#include <stdio.h>
#include <unistd.h>

int main() {
	int i, ret;
	printf("program started.\n");
	ret = fork();
	printf("fork() returned: %d\n", ret);
	if(ret == 0) {
		for(i=0; i<300; i++) {
			printf("child: %d\n", i);
		}
	} else {
		for(i=0; i<300; i++) {
			printf("parent: %d\n", i);
		}	
	}
	printf("program completed.\n");
	return 0;
}
// terminal> gcc -o fork.out fork2.c
// terminal> ./fork.out
```

- 5. to see process info 
  *  ps displays information about a selection of the active processes.  
  * count of all process running
  >  ps -e | wc -l
  * here -o : User-defined format
   + pid : 
  > ps -e -o pid,state,cmd
  * to see child and parent pid
  > ps -e -o pid,ppid,cmd

  >  ps -e -o pid,ppid,state,cmd
```cmd
          -e :Select all processes.  Identical to -A.
   here   -o : User-defined format
 KEY   LONG         DESCRIPTION
       c     cmd          simple name of executable
             state        Process state       
       C     pcpu         cpu utilization
       k     utime        user time
       o     session      session ID
       p     pid          process ID
       P     ppid         parent process ID
       s     size         memory size in kilobytes
       U     uid          user ID number
       u     user         user name
       y     priority     kernel scheduling priority

```

#### MCQ:Question
- 6. demo for orphan process
*  init or systemd process id 1
* process with process id 1 is init in older linux , and systemd in newer linux
* when parent process is terminated then the child process is called orphan process , and the process is taken by init  process through , a reaper process which is at    /lib/systemd/systemd --user
* ownership of orphan process taken by init process pid 1
* if child process completes earlier then parent , we get [fork2.out] <defunct>

```c++
#include <stdio.h>
#include <unistd.h>

int main() {
	int i, ret;
	printf("program started.\n");
	ret = fork();
	printf("fork() returned: %d\n", ret);
	if(ret == 0) {
		for(i=0; i<30; i++) {
			printf("child: %d\n", i);
		}
	} else {
		for(i=0; i<15; i++) {
			printf("parent: %d\n", i);
		}	
	}
	printf("program completed.\n");
	return 0;
}

// terminal> gcc -o fork.out fork2.c
// terminal> ./fork.out

```


7. demo of Zombie state
* if child process completes earlier then parent , we get [fork2.out] <defunct>, i.e child process is in zombie state
* as child process need a confirmation from parent process, to terminate , by system call , wait ()
```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int i, ret, s;
	printf("program started.\n");
	ret = fork();
	printf("fork() returned: %d\n", ret);
	if(ret == 0) {
		for(i=0; i<15; i++) {
			printf("child: %d\n", i);
			sleep(1);
		}
		_exit(3); // child exit status = 3
	} else {
		for(i=0; i<30; i++) {
			printf("parent: %d\n", i);
			sleep(1);
			if(i==15) {
				wait(&s); // get exit status of child process from its pcb and release pcb of the child.
				printf("child exit status: %d\n", WEXITSTATUS(s));
			}
		}	
	}
	printf("program completed.\n");
	return 0;
}

// terminal> gcc -o fork.out fork6.c
// terminal> ./fork.out


            

```


8. to avoid Zombie state using wait

```c++
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/wait.h>
 
 // wait() syscall does following
 // 1. block parent execution until any of its child is terminated
 // 2. read exit status of the child (out param of wait()) 
 // 3. release PCB of the child process
 
  // after wait() child proces is no more zombie 
  
  
  int main() {
      int i, ret, s;
      printf("program started.\n");
      ret = fork();
      printf("fork() returned: %d\n", ret);
      if(ret == 0) {
          for(i=0; i<15; i++) {
              printf("child: %d\n", i);
              sleep(1);
          }
          _exit(3); // child exit status = 3
      } else {
          for(i=0; i<30; i++) {
              printf("parent: %d\n", i);
              sleep(1);
              if(i==15) {
              ret = wait(&s); // get exit status of child process from its pcb and release pcb of the child.
                  printf("child (%d)exit status: %d\n",ret, WEXITSTATUS(s));
              }
          }
      }
      printf("program completed.\n");
      return 0;
  }
  
  // terminal> gcc -o fork.out fork6.c
                                                        

```

9. waitpid() 
> waitpid(child_pid,&exit_status,flags ) syscall does following
1. block parent execution until any of a given child is terminated
-  if arg1=-1 then wait for any child. 
 2. read exit status of the child (out param of wait()) 
 3. release PCB of the child process
 -  returns pid of child process on success 
 4.  flags -
 - behaviour of waitpid() call 
 - 0 - same as wait() -- block the parent process until termination of child
 -  flag : WNOHANG - do not block parent process
  5. if child already terminated , get its exit status and return its pid 
  -  if no child is already terminated, returns error codde 
  - after wait() child proces is no more zombie  

# day 6
## MCQ 
1. In C language, ftell() returns the current file position of the specified stream with respect to the starting of the file. This function is used to get the total size of file after moving the file pointer at the end of the file

2. The C library function void rewind(FILE *stream) sets the file position to the beginning of the file of the given stream.

3. **to remove IPC related Objects**  
+ if we forget to delete mesage queue, then message queue will still remain in memory, i.e resource leakage, so to remove it, we have two command (by key and by value)
* ipcrm - remove certain IPC resources
* ipcrm  removes  System  V  inter-process  communication (IPC)
 objects and associated data structures from the  system.   In
 order  to  delete such objects, you must be superuser, or the
 creator or owner of the object.
* command to remove ipc related object
> ipcrm -extension
```bash

  -M, --shmem-key shmkey
 Remove the shared memory segment created  with  shmkey after the last detach is performed.
 -m, --shmem-id shmid
Remove  the  shared memory segment identified by shmid after the last detach is performed.
 -Q, --queue-key msgkey Remove the message queue created with msgkey.
-q, --queue-id msgid Remove the message queue identified by msgid.
-S, --semaphore-key semkey Remove the semaphore created with semkey.
-s, --semaphore-id semid Remove the semaphore identified by semid.
```

4. what is return type/value of wait system call, 
* wait()
>  pid_t wait(int *wstatus);
*  All  of these system calls are used to wait for state changes in a child of the calling  process,  and  obtain  information about  the  child whose state has changed.
*  A state change is considered to be: the child terminated; the child was stopped by  a  signal;  or the child was resumed by a signal.  In the case of a terminated child, performing a wait allows the system  to release the resources associated with the child; if a wait is not performed, then the terminated child remains in a "zombie" state
+ wait():  on success, returns the process ID of the terminated child;
+  on error, -1 is returned.

1. open ( )
+  open(), openat(), and creat() return the new file descriptor,
       or  -1  if  an  error  occurred

6. close () : close a file descriptor
+  close()  returns  zero on success.  On error, -1 is returned,

7. read()
+ 
>  ssize_t read(int fd, void *buf, size_t count);
* read()  attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
*  If the file offset is at or  past  the  end of file, no bytes are read, and read() returns zero.
+  On success, the number of bytes read is returned
+   On error, -1 is returned

8. write()  : write to a file descriptor
>  ssize_t write(int fd, const void *buf, size_t count);
*  write()  writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor fd.
+  On  success,  the  number  of bytes written is returned
+   On error, -1 is returned


9. lseek : reposition read/write file offset
>   off_t lseek(int fd, off_t offset, int whence);
* lseek() repositions the file offset of the open file description associated with the file descriptor fd to  the  argument offset according to the directive whence as follows:
+  SEEK_SET
 - The file offset is set to offset bytes.
+ SEEK_CUR
- The  file  offset  is set to its current location plus  offset bytes.
+ SEEK_END
The file offset is set to the size of  the  file  plus offset bytes.

*  Upon successful completion,  lseek()  returns  the  resulting  offset  location  as  measured in bytes from the beginning of the file.
+   On error, the value  (off_t) -1  is  returned

10. fork () : create a child process
>  pid_t fork(void);
* fork()  creates  a  new  process  by  duplicating the calling process.  The  new  process  is  referred  to  as  the  child process.   The  calling  process is referred to as the parent process.
*   On success, the PID of the child process is returned  in  the parent,  and  0  is returned in the child.
*  On failure, -1 is returned in the parent, no  child  process  is  created,  and errno is set appropriately.


11.  waitpid() 
> waitpid(child_pid,&exit_status,flags ) syscall does following
1. block parent execution until any of a given child is terminated
-  if arg1=-1 then wait for any child. 
 2. read exit status of the child (out param of wait()) 
 3. release PCB of the child process
 -  returns pid of child process on success 
 4.  flags -
 - behaviour of waitpid() call 
 - 0 - same as wait() -- block the parent process until termination of child
 -  flag : WNOHANG - do not block parent process
  5. if child already terminated , get its exit status and return its pid 
  -  if no child is already terminated, returns error codde 
  - after wait() child proces is no more zombie  


## notes
1. **command for executabele file** 
* display information from object files.
> objdump -t exec_file.out
+ ELF files are Executable Linkable Format 
+ which consists of a symbol look-ups and relocatable table, that is, it can be loaded at any memory address by the kernel and automatically, all symbols used, are adjusted to the offset from that memory address where it was loaded into.
*  Displays information about ELF files
> readelf -h exec1.out


2. **File SysCalls**
- 1. leseek( )
  + Same as fseek()
* newpos = lseek(fd, offset, origin)
	* Internally change current file position (f_pos) stored in OFT of the file.
	* f_pos -- indicate next byte to be read/written
	* Same as newpos = fseek(fp, offset, origin)
	* offset can be +ve or -ve based on origin.
	* origin = SEEK_SET (beginning of file)
		* offset must be +ve
	* origin = SEEK_END (end of file)
		* offset must be -ve
	* origin = SEEK_CUR (current position)
		* offset can be +ve or -ve
		* +ve = forward move
		* -ve = backward move

3.  Mounting
* CD/DVD -- E: -- CDFS/iso9660
* Windows/modern Linux does mounting automatically.
	* Windows: mountvol.exe
	* Linux: mount
* In Linux mounting can be done manually.
	```shell
     > sudo mount -t vfat /dev/sdb1 /mnt
	   > ls /mnt
	   > ...
	   > sudo umount /mnt
  ```
4. Process Management

*  Process definition
*  Process Life Cycle
* Pre-emptive scheduling vs Non-pre-emptive scheduling
* Process creation
*  fork() syscall, using this, process based multi tasking 
*  orphan process
* zombie process

5.  wait()/waitpid() syscall
* wait() -- UNIX syscall
* waitpid() -- Linux syscall
*  All  of these system calls are used to wait for state changes in a child of the calling  process,  and  obtain  information about  the  child whose state has changed. 
*   A state change isconsidered to be:
+  the child terminated; 
+  the child was stopped by  a  signal;  or
+   the child was resumed by a signal.
*  In the case of a terminated child, performing a wait allows the system  to release the resources associated with the child; 
*  if a wait is not performed, then the terminated child remains in a "zombie" state .
*   wait():  on success, returns the process ID of the terminated child; on error, -1 is returned.


### differnce between exit() and _exit() syscall
* exit() -- C library function -- <stdlib.h>
	* exit the current process -- internally calls _exit() syscall.
* _exit() -- syscall -- <unistd.h>
	* Release all resources (memory, ipc, ...) occupied by the process.
	* Write its exit status into its PCB.


## exec_system call
1. it does'nt create a process, it loads new program in calling process memory
#### mcq : imp
2. exec loads new program in calling process memory, whereas fork creates new process
3. loader that loads program in memory, is exec() itself
4. exec is a family of function, it has 7 function 
 *  int execl()
 *  int execlp()
 *  int execle()
 *  int execv()
 *  int execvp()
 *  int execvpe()
* where  : 
 + l : varaible argument list for command line arguments, to pass process 
 + v : argument vector/array --> commandline arguments 
 + p : child program will be searched in all directories mantioned in PATH variable
 + e :  environment variables to be given to child 
     - example in C main (envp)

5. if directly call exec, a new program loaded on parent process, and it data is overloaded, as no child is created for being over writeen
* to find path of command file 
> which command
* system call to ge pid of self  
> getpid()
* and parent
> getppid()

- 1. using l and v  and vp q
```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int ret, err, s;
	printf("parent started.\n");
	ret = fork();
	if(ret == 0) {
		// cal -y 2020
		
		// err = execl("/usr/bin/cal", "cal", "-y", "2020", NULL);
		
		//char *args[] = { "cal", "-y", "2020", NULL };
		//err = execv("/usr/bin/cal", args);
		
		char *args[] = { "cal", "-y", "2020", NULL };
		err = execvp("cal", args);

		if(err < 0) {
			perror("exec() failed");
			_exit(1);
		}
	}
	else {
		waitpid(ret, &s, 0);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}
	printf("parent completed.\n");
	return 0;
}

            
```
- 2. using strtok 
```c++
 #include <stdio.h>
 #include <string.h>
 
 int main(){
 char cmd[512], *ptr;
 
 printf("cmd> ");
     gets(cmd);
 
  ptr = strtok(cmd, " " );
  puts(ptr);
  
  do {
  
  ptr = strtok(NULL, " " );
  puts(ptr);
  
   } while(ptr != NULL);
  
  return 0;
  
  }      
```

- 3. 
```c++
#include <stdio.h>
#include <string.h>

int main() {
	char cmd[512], *ptr, *args[32];
	int i;
	
	printf("cmd> ");
	gets(cmd);
	i = 0;
	ptr = strtok(cmd, " ");
	//puts(ptr);
	args[i++] = ptr;

	do {
		ptr = strtok(NULL, " ");
		//puts(ptr);
		args[i++] = ptr;
	}while(ptr != NULL);

	for(i=0; args[i]!=NULL; i++)
		puts(args[i]);

	return 0;
}


```

- 4. shell 
* as shell interanlly does fork + exec , to run commands 
* some commands are called bash built in or interanl commands , like exit,cd,alias,export
* external commands have their exe under /bin/
*  
```c++
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char cmd[512], *ptr, *args[32];
	int i, ret, err, s;
	
	printf("cmd> ");
	gets(cmd);
	i = 0;
	ptr = strtok(cmd, " ");
	//puts(ptr);
	args[i++] = ptr;

	do {
		ptr = strtok(NULL, " ");
		//puts(ptr);
		args[i++] = ptr;
	}while(ptr != NULL);

	//for(i=0; args[i]!=NULL; i++)
	//	puts(args[i]);

	ret = fork();
	if(ret == 0) {
		err = execvp(args[0], args);
		if(err < 0) {
			perror("bad command");
			_exit(1);
		}
	} 
	else
		wait(&s);

	return 0;
}



            
```

- 6. 
```c++
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char cmd[512], *ptr, *args[32];
	int i, ret, err, s;

	while(1) {
		printf("cmd> ");
		gets(cmd);
		i = 0;
		ptr = strtok(cmd, " ");
		//puts(ptr);
		args[i++] = ptr;

		do {
			ptr = strtok(NULL, " ");
			//puts(ptr);
			args[i++] = ptr;
		}while(ptr != NULL);

		//for(i=0; args[i]!=NULL; i++)
		//	puts(args[i]);
		
		if(strcmp(args[0], "exit") == 0 || strcmp(args[0], "bye") == 0)
			_exit(0);
		else if(strcmp(args[0], "cd") == 0)
			chdir(args[1]);
		else {
			ret = fork();
			if(ret == 0) {
				err = execvp(args[0], args);
				if(err < 0) {
					perror("bad command");
					_exit(1);
				}
			} 
			else
				wait(&s);
		}
	}
	return 0;
}



            
```



- 7. to get session id, process group id ,thread id 
* where session if, for each bash terminal opened, bash pid is session id
* for a no of commands running together makes a group, called process group, having a process group id
* similarly thread are created ,first being main thread, each process have multiple  threads, having thread id (tig)
> ps -e -m -o pid,tid,tgid,nlwp,cmd
* output:  PID   TID  TGID NLWP CMD

> ps -e -o pid,sid,cmd 


>  ps -e -o pid,pgid,cmd 
*  PID  PGID CMD

- 8.   The  exec()  functions  return only if an error has occurred.The return value is -1,

## Inter Process Communicaton (IPC) 

1. memory of one process cannot be shared with another process, so IPC
2. LInux specific IPC mechanism 
* 1. Signals
* 2. Shared memory
* 3. message queue
* 4. pipe
* 5. Socket

### 3. Signals
* in it data doesnt travel from one process to another, still communication happens
* e.g : call and miscall , having specific meaning between friends, without voice data 
* so there are set of predefined signals, which communicate, not actual data 
* so the signals can be send by,
  +  one process can send signal to another process,
  + OS to any Process, 
  + but we/user cannot send signal to OS
  * default action takes plece
  1. TERM : terminate action 
  2. CORE : Aborted and creates core dump 
  3. STOP : suspend 
  4. CONT : resume suspended
  + Default action is to stop the process.
  5. IGN : not handled, get ignored  
  
  > man 7 signals
  * to see all signals 
  > kill -l 
  
  * Importent signals 
  1. SEGINT (2)
  + Cltr +C , interanlly generates SEGINT , and default action of it  TERM
  2. SIGTERM(15)
  + default action TERM , when shutdown , SIGTERM terminates process, normally 
  3. SIGKILL(9)
  + default action TERM 
  + when shutdown, SIGKILL forcibely terminates process
  4. SIGSTOP (19)
  + cltr + S :i.e STOP action , so process get suspended
  5. SIGCONT (18)
  + cltr + q , continues suspended process
  6. SIGSEGV 
  + segment violation (due to dangling pointer), its CORE action
  7. SIGCHLD (17)
  + child send signal to parent , while terminating   [as we dont know how to handle it till now so action is IGN] 
  
  #### Send Signals 
  * implemented loop.c, infinite loop and execute it 
  + in terminal 1
  >  gcc -o loop.out loop.o
  >  ./loop.out 
  + terminal 2
  > ps -e
  * find pid of loop.out
  > kill -2 pid 
  * try signals : SIGINT, SIGTERM,SIGKILL,SIGSTOP,SIGCONT,SIGSEGV,SIGHUP,SIGCHLD
  * To kill multiple processes of the same program
  	>  terminal> pkill -9 chrome
  	>  terminal> pkill -KILL chrome
  
  * closing terminal : SIGHUB signal is given 
  + i.e  hang up signal - meaning parent terminal is closed
  + so to ignore hangup signal,  - HUP , we can use
  > nohup ./loop.out 
  + so app doesnt close even in terminal get closed, example used in AWS
  
  * if multiple program nunning , so how to terminate them using kill 
  + we cannot kill process group id , 
  + we can use
  
  > kill -signum pid
  > kill -signame pid
   
  > pkill -signum programname
  > pkill -signame programname 
  
  * to kill all process
  > killall
  
  * to kill all instance of a program 
  > kill -9  pid
  
  #### two signals cannot be handled
  1. SIGKILL,SIGSTOP , as used in shutdown 
  
  #### recieving signal
  1. signal is software counter part of hardware interrupt
  2. when a process is executing , meanwhile signal is send to process, it pause current process,
  + goes to table, called signal handler table (having 64 signal, handler)
  + here it gets signal handler(), and implement it, 
  
  *  to handle a signal ,is  2 step  process 
  1. write signal handler
  2. make its entry into signal handler table 
  - signal system call
  - 1. demo to handle a signal 
  ```c++
  #include <stdio.h>
  #include <unistd.h>
  #include <signal.h>
  
  // signal handling demo
  
  //step1: implement signal handler function
  void sigint_handler(int sig) {
  	printf("signal is caught: %d\n", sig);
  }
  
  int main() {
  	int i=0;
  	//step2: register signal handler (in signal handler table of current process).
  	signal(SIGINT, sigint_handler);
  	while(1) {
  		printf("loop: %d\n", ++i);
  		sleep(1);
  	}
  	return 0;
  }
  
  //terminal 1> gcc -o signal.out signal1.c
  //terminal 1> ./signal.out 
  
  // ctrl + C
  
  //terminal 2> pkill -2 signal.out
  ```
  
  
  - 2. 
  
  ```c++
  #include <stdio.h>
  #include <unistd.h>
  #include <sys/wait.h>
  #include <signal.h>
  
  // step1: implement signal handler function
  void sigchld_handler(int sig) {
  	int s;
  	wait(&s); // get exit status of child process from its pcb and release pcb of the child.
  	printf("child exit status: %d\n", WEXITSTATUS(s));
  }
  
  int main() {
  	int i, ret, s;
  	// step2: register signal handler
  	signal(SIGCHLD, sigchld_handler);
  
  	printf("program started.\n");
  	ret = fork();
  	printf("fork() returned: %d\n", ret);
  	if(ret == 0) {
  		for(i=0; i<10; i++) {
  			printf("child: %d\n", i);
  			sleep(1);
  		}
  		_exit(0); // child exit status = 3
  	} else {
  		for(i=0; i<30; i++) {
  			printf("parent: %d\n", i);
  			sleep(1);
  		}	
  	}
  	printf("program completed.\n");
  	return 0;
  }
  
  // terminal> gcc -o signal.out signal2.c
  // terminal> ./signal.out
              
  ```
  - 3. Signal convention 
  * UNIX
  * signal ( ) -> 
  + register signal handler for given signal , Internally it make its entry into process( PCB)
   signal handler table
  +  it return s old sig handler address
  * Linux 
  1. sigaction() 
  + register sig handler, enchanced signal() sys call
  + signal handler are typlically registered at the start of application 
  
### 4. Shared Memory 

0. shred memory region is created in user space
+ Multiple process can have pointers to shared memory region (attached processes)
+ Any process can write into shared memory and other processes can read from it directly
+ Fastest IPC mechanism 

1. demo on  using fork , a duplicate process of parent process is created, so each process have a copy of varaibles in program/process, so the out put of this program is : 
> child , 1,2,3, 
> parent , -1,-2 ,...-12 

```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

struct my_data {
	int count;
};

struct my_data var;

int main() {
	int i, ret, s;
	struct my_data *ptr;
	ptr = &var;
	ptr->count = 0;

	ret = fork();
	if(ret == 0) {
		for(i=0; i<10; i++) {
			ptr->count++;
			printf("child: %d\n", ptr->count);
			sleep(1);
		}
	}
	else {
		for(i=0; i<10; i++) {
			ptr->count--;
			printf("parent: %d\n", ptr->count);
			sleep(1);
		}
		waitpid(-1, &s, 0);
		printf("final count = %d\n", ptr->count);
	}
	return 0;
}

// terminal> gcc -o shm.out shm.c
// > ./shm.out
```

2. ifter using fork, how to maintain a common varaible for both process, i.e 
+ Shared Memory Area (SMA) : is a special memory areas, which can be shared among multiple process 
+ to create SMA , OS interanlly creates , shared Memory Object(SMO)
  * here in SMO we have 
  1. key : like pid
  2. mode : 
  3. n attached : no of process connected
  4. addr : address of SMA 
  5. size : size of SMA
  6. owner : owner of SMA

+ to keep reference of SMO we have share memory Table (SMT), and reference index is called share memorry id (smid) 
* command to show shared memory, message queue , semaphore 
> ipcs
```bsh
----- Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status 

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
```


*  runlevel command  -->  Print previous and current SysV runlevel
* command tells , what level running, 
+ if runlevel 3: we have CLI
+ if runlevel 5: we have GUI  
> run level 

3. 

```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SHM_KEY	0x1234

struct my_data {
	int count;
};

int main() {
	int i, ret, s, shmid;
	struct my_data *ptr;
	
	// create shared memory region
	shmid = shmget(SHM_KEY, sizeof(struct my_data), IPC_CREAT | 0600);
	if(shmid < 0) {
		perror("shmget() failed");
		_exit(1);
	}

	// get pointer to shared memory
	ptr = (struct my_data*) shmat(shmid, NULL, 0);
	if(ptr == (void*)-1) {
		perror("shmat() failed");
		_exit(1);
	}
	
	ptr->count = 0;

	// create child process
	ret = fork();
	if(ret == 0) {
		for(i=0; i<10; i++) {
			// child: increment the count
			ptr->count++;
			printf("child: %d\n", ptr->count);
			sleep(1);
		}
		// release shared memory pointer
		shmdt(ptr);
	}
	else {
		for(i=0; i<10; i++) {
			// parent: increment the count
			ptr->count--;
			printf("parent: %d\n", ptr->count);
			sleep(1);
		}
		waitpid(-1, &s, 0);
		printf("final count = %d\n", ptr->count);
		// release shared memory pointer
		shmdt(ptr);
		// delete shared memory region
		shmctl(shmid, IPC_RMID, NULL);
	}
	return 0;
}

```
```bash
> gcc -o shm.out shm2.c 
> ./shm.out 

> ipcs 

#  Shared Memory Segments -------- 
  # key          shmid      owner      perms      bytes      nattch     stat
# 0x00001234 65576      sunbeam    600        4          2             
> 

```

4.  to mark for deletion,  shmdt , so we see 
> ipcs 
* stst = dest 
+ i.e mark for deletion 

```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SHM_KEY	0x1234

struct my_data {
	int count;
};

int main() {
	int i, ret, s, shmid;
	struct my_data *ptr;
	
	// create shared memory region
	shmid = shmget(SHM_KEY, sizeof(struct my_data), IPC_CREAT | 0600);
	if(shmid < 0) {
		perror("shmget() failed");
		_exit(1);
	}

	// get pointer to shared memory
	ptr = (struct my_data*) shmat(shmid, NULL, 0);
	if(ptr == (void*)-1) {
		perror("shmat() failed");
		_exit(1);
	}
	
	ptr->count = 0;
		
	// mark shared memory region for deletion
		// shared memory region will be deleted, when no processes attached to it.
	shmctl(shmid, IPC_RMID, NULL);

	// create child process
	ret = fork();
	if(ret == 0) {
		for(i=0; i<10; i++) {
			// child: increment the count
			ptr->count++;
			printf("child: %d\n", ptr->count);
			sleep(1);
		}
		// release shared memory pointer
		shmdt(ptr);
	}
	else {
		for(i=0; i<10; i++) {
			// parent: increment the count
			ptr->count--;
			printf("parent: %d\n", ptr->count);
			sleep(1);
		}
		waitpid(-1, &s, 0);
		printf("final count = %d\n", ptr->count);
		// release shared memory pointer
		shmdt(ptr);
		// nattached count of shm falls to zero, hence shared memory object is deleted.
	}
	return 0;
}

// terminal> gcc -o shm.out shm2.c 
// terminal> ./shm.out          
```

### 5. Message Queue  (MQ)
0. Process send message to kernal (copied from user space to kernel space ) and then other process recieve it from the kernel (copied from kernel space to user space). 
+ Slower than Shared memory
+ Bi-directoional data transfer (message types will differ)
+ Packet based data transfer

1. the way SMS is send  from mobile to tower, tower to 2nd mobile, same way message queue works
2. process 1 to kernel (message queue object) from kernal to process 2
3. in message Queue Object (MQO) we have
+ 1. KEY : key of message 
+ 2. COunt : of message 
+ 3. list : of message , i.e  a pointer to queue 
+ 4. size : in bytes
+ 5. waiting queue : mainly for reciever process
4. to create a track of message queue object(MQO), we have a message queue table(MQT) , 
+ which hold reference to MQO , it index is called mqid
5. here for each message from a process ,has a message  type  (contains address)
+ it must be long type ,and at start of message block
+ as IPC developed by one developer, so sender and reciever adress ,we will know 
#### MCQ: 
6. if we forget to delete mesage queue, then message queue will still remain in memory, i.e resource leakage, so to remove it, we have two command (by key and by value)
* ipcrm - remove certain IPC resources
* ipcrm  removes  System  V  inter-process  communication (IPC)
 objects and associated data structures from the  system.   In
 order  to  delete such objects, you must be superuser, or the
 creator or owner of the object.

> ipcrm 
```bash

 -Q, --queue-key msgkey
 Remove the message queue created with msgkey.

 -q, --queue-id msgid
 Remove the message queue identified by msgid.


```


- 1.  demo on message queue 
```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MQ_KEY	0x4321
#define MSG_LEN	32

struct my_data {
	long type;
	char str[MSG_LEN];
};

int main() {
	int mqid, ret, s;

	// create message queue
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if(mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child -- sender
		struct my_data m1;
		m1.type = 123;
		printf("child: enter a string: ");
		scanf("%s", m1.str);
		printf("child: sending message ...\n");
		// send message in message queue (with type=123).
		msgsnd(mqid, &m1, MSG_LEN, 0);
	}
	else {
		// parent -- receiver
		struct my_data m2;
		printf("parent: waiting for child message.\n");
		// receive message from message queue (with type=123).
		msgrcv(mqid, &m2, MSG_LEN, 123, 0);
		printf("parent: received %s \n", m2.str);

		wait(&s);

		// delete message queue
		msgctl(mqid, IPC_RMID, NULL);
	}
	return 0;
}

//terminal> gcc msgque.c -o msgque.out
//terminal> ./msgque.out           
```

### 6. PIPE

0. Unidirectional data transfer 
+ this is Stream Based, (i.e not predefined like message) 
+ Stream is a sequence of bytes, so no predefined object length
+ Kernel maintains a buffer of fixed size (modern Linux default is 64 Kb), in which data is hold until,it is read by reader Process. 
+ pipe has two ends : 
  - 1. writer end 
  - 2. reader end
1. two types of pipes
* 1. Unnamed pipe (pipe)
  + communication between two related process (in same process group)
  + e.g :  who | wc 
  + created using pipe() syscall (system call)
  ```bash
  # here , arr --> is out parameter, arr[0] -->reader end , arr[1] ---> writer end of pipe 
     int arr[2];
		 ret = pipe(arr);
	#  arr[0] -- file descriptor of reader end of pipe
	#  arr[1] -- file descriptor of writer end of pipe 
  
  ``` 
- 1. demo for unnamed pipe
*  for pipe, we have a pipe Object , which contains 
  * 1. *buf : a pointer to pipe buffer(i.e a circular queue), 
  * 2. read| front :
  * 3. count : 
  * 4. waiting queue : 

+ whose data is referenced in inode table , with no data area 
+ pipe have read and write, so two entries in OFT(open file table),for read and wiite, having pointer to same inode 
+  in PCB, there is a OFDT(open file discriptor table), having standard entries, stdin(1),stdout(1), stderr(2), also 
+  reader file discriptor i.e end a pointer from OFT table(3), writer file discriptor(4), 

+ after creation of pipe , use fork() on it (that copies whole process,its PCB containing OFDT), this child process also have a reference to OFT, so now a pipe with four end is created (i.e child in parent pipe )
+ so we must keep two ends, and close other 2 end,
+  depend who sends data, close it  reader ends , and someone wanna read, close writer end

```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int ret, s;
	int arr[2];

	// create pipe
	ret = pipe(arr);
	if(ret < 0) {
		perror("pipe() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child -- sender
		char str1[32];
		printf("child: enter a string: ");
		scanf("%s", str1);
		printf("child: sending message ...\n");
		// send data in the pipe.
		write(arr[1], str1, sizeof(str1));
		
		// close pipe write end
		close(arr[1]);
	}
	else {
		// parent -- receiver
		char str2[32];
		printf("parent: waiting for child message.\n");
		// receive message from pipe.
		read(arr[0], str2, sizeof(str2));
		printf("parent: received %s", str2);

		wait(&s);

		// close pipe read end
		close(arr[0]);
	}
	return 0;
}



```

* 2. Named Pipe (fifo)
  + communication between any two proceeses 
  + it is a special file denoted by (p) , created using mkfifo command/syscall
  + Writer proces open pipe in write mode and reader process open it in read node 
     * File created on disk 
     * Number of data blocks are always zero
  + Writer proces open pipe in write mode and reader process open it in read mode 

- 0. create fifo file
```bash
mkfifo myfifo
```

- 1. wr_pipe.c
```c++
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fw;
	char str[40];
	
	printf("WR: opening fifo.\n");
	fw = open("myfifo", O_WRONLY);
	if(fw < 0) {
		perror("failed to open fifo");
		_exit(1);
	}

	printf("WR: enter a string: ");
	scanf("%s", str);

	write(fw, str, sizeof(str));
	printf("WR: data is sent.\n");

	close(fw);
	return 0;
}

//terminal> mkfifo ~/myfifo
//terminal> ls -l ~

//terminal> gcc -o wr_pipe.out wr_pipe.c 
//terminal> ./wr_pipe.out



            
```

- 2. r_pipe.c      
```c++
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fr;
	char str[40];
	
	printf("RD: opening fifo.\n");
	fr = open("myfifo", O_RDONLY);
	if(fr < 0) {
		perror("failed to open fifo");
		_exit(1);
	}

	printf("RD: waiting for data...\n");
	read(fr, str, sizeof(str));

	printf("RD: data is received: %s.\n", str);

	close(fr);
	return 0;
}

//terminal> gcc -o rd_pipe.out rd_pipe.c 
//terminal> ./rd_pipe.out            
```

-3. run 
```bash
> ./wr_pipe.out
message
# we get messag here in rt
> ./rt_pipe.out
message

```

### 7. Socket

1. Socket is communication end point
2. socket developed by BSD UNIX
3. Socket is extension of pipe COncept
 + but it is bi-directional 
4. Socket has many types ( calledAddress families)
+ 1. AF_UNIX
+ 2. AF_INET
+ 3. AF_BLUFTOUTH


5. AF_UNIX socket
* communication between two processes on same computer 
* it has special file (s)

6. AF_INET (internet socket)
* communication betweeen two processes on same/ diff computers
* made up of inet socket = ip adress + port number
+ it could be TCP or UDP socket , depending on underlying protocol 
+ in java for TCP class name Socket , Server Socket class, for UDP, datagram socket , and datagram packet


####  Linux run levels 
1. user give services , based on levels/run level 
2. linux run levels
* 
+ 0. shutdown  pc --> command : 
> sudo init 0 
+ 1. single user mode( minimum services ) 
+ 2. multi user mode (no network in min services)
+ 3. multi user mode + network 
   * so server machine require this level
+ 4. reserved (unused)
+ 5. multi user + network + GUI 
+ 6. reboot pc  : 

3. to know current run level  mode : 
> runlevel 

4.  to change runlevel ,
> sudo init rn
* where rn : run level
* we can use to go to level 3
> sudo init 3

5. to see RAM usage on PC
> free -mh