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


            
