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


            

