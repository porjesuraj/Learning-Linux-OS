#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// waitpid(child_pid,&exit_status,flags ) syscall does following
// 1. block parent execution until any of a given child is terminated
// if arg1=-1 then wait for any child. 
// 2. read exit status of the child (out param of wait()) 
// 3. release PCB of the child process
// returns pid of child process on success 

// flags -- behaviour of waitpid() call 
// 0 - same as wait() -- block the parent process until termination of child

// flag : WNOHANG - do not block parent process
    // if child already terminated , get its exit status and return its pid 
	 // if no child is already terminated, returns error codde 

// after wait() child proces is no more zombie 


int main() {
	int i, ret, s;
	printf("program started.\n");
	ret = fork();
	printf("fork() returned: %d\n", ret);
	if(ret == 0) {
		for(i=0; i<15; i++) {
			printf("child: %d\n", i);
			sleep(4);
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
// terminal> ./fork.out

