# Operating Systems

## 1. Syllabus Operating System
0. Introduction Operating System
> galvin book chapter 1 and 2
1. Linux System
	* History
	* Architecture
	* Linux kernel
		* Monolithic
		* Micro-kernel
		* Modular
2. Shell
	* Types of shells
	* BASH shell
	* Linux file system
		* Linux directories
		* Absolute vs Relative path
	* File system commands
		* Directory related commands
		* Files related commands
		* File permissions/owner
		* Shell wild-card characters
	* Regular expressions
	* Advanced topics
		* IO redirection
		* Pipe
	* VI editor
		* .vimrc
	* Shell scripts
		* Variables
		* read and echo
		* if-then-else, elif, case and test command
		* while, until and for loop
		* positional parameters
		* functions
		* arrays
		* string operations
		* Directory stack
	* Shell files
		* .bashrc
		* .profile, .bash_profile
		* .bash_logout
		* .bash_history
	* Networking commands
		* ifconfig
		* netcat
		* ssh
3. System calls
	* User vs kernel mode
	* Preemptible/Non-preemptible kernel
4. CPU Scheduling
	* Pre-emptive vs non-preemptive
	* Scheduling algorithms
5. Process
	* Introduction & life cycle
	* Linux process commands: ps, top
	* Process creation: fork(), exec(), wait()
	* Orphan & zombie processes
6. Inter-process communication
	* Signals - Sending (kill command) & handling
	* Shared memory
	* Message queue
	* Pipe and Fifo
7. Threads
	* Introduction
	* Process vs Threads
	* Thread creation
	* Thread synchronization
		* Semaphore
		* Mutex
	* Producer-consumer problem
	* Deadlock
	* User vs kernel threads
8. File & IO management
	* File & File system
	* File system architecture
	* File vs Directory internals
	* Hard vs Symbolic links
	* File IO system calls
	* Disk allocation mechanism - ext2/ext3
	* Disk scheduling algorithms
9. Memory management
	* MMU introduction
	* Virtual memory / Swap area
	* Segmentation vs Paging
	* TLB and multi-level paging
	* Page fault handling
	* Page replacement algorithms
	* Dirty bit and copy-on-write

## 2.  Evaluation 
* Theory : 40 marks - CCEE(5-jan-2021)
      * MCQ based on 
        - linux commands,
        -  shell scripts, 
        -  linux system call, 
        -  rest conceptual question 

* Lab: 40 marks
      * Linux commands - 10 marks
          * Subjective question 
      * Bash shell scripts - 20 marks
          * Test case based
      * System call programming - 10 marks
          * C programming : file upload               
* Internals: 20 marks - MCQ



```bash
(ls, cp, mv, lpr, sort, grep, cat, tac, more, head, tail, man, whatis, whereis, locate, find, diff,
file, rm, mkdir, rmdir, cd, pwd, ln and ln –s, gzip and gunzip, zip and unzip, tar an its variants,
zcat, cal, bc and bc –l, banner date, time, wc, touch, echo, who, finger, w, whoami, who am
i, alias, unalias, touch, push, pop, jobs, ps, etc
```