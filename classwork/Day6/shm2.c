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

// terminal> gcc -o shm.out shm2.c 
// terminal> ./shm.out 




            
