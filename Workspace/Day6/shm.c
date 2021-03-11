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




            
