#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;
int count = 0;

void* incr_thread_func(void *param) {
	int i;
	for(i=1; i<=10; i++) {
		// P(s);
		sem_wait(&s);
		count++;
		printf("incr: %d\n", count);
		// V(s);
		sem_post(&s);
		sleep(1);
	}
	return  0;	
}

void* decr_thread_func(void *param) {
	int i;
	for(i=1; i<=10; i++) {
		// P(s);
		sem_wait(&s);
		count--;
		// V(s);
		sem_post(&s);
		printf("decr: %d\n", count);
		sleep(1);
	}
	return  0;	
}

int main() {
	pthread_t t1, t2;
	int i, ret;
	// create semaphore with initial count=1 (arg3).
	sem_init(&s, 0, 1);
	ret = pthread_create(&t1, NULL, incr_thread_func, NULL);
	ret = pthread_create(&t2, NULL, decr_thread_func, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("final count: %d\n", count);
	// destroy semaphore
	sem_destroy(&s);
	return 0;
}


// terminal> gcc thread4.c -o thread.out -lpthread
// terminal> ./thread.out



            

