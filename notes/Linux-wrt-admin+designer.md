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
- 1. **Boot block**
  *  contains bootstap laoder 
  *  GRUB (grand unified bootLoader) for linux 
- 2. **super block**
  * it contains  info about partition, 
  * like label of storage, storage info , used, free space
       
- 3. **inode block**
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


6. 