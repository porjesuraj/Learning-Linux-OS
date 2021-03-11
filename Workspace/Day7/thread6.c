#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t m;
int count = 0;

void* incr_thread_func(void *param) {
	int i;
	for(i=1; i<=10; i++) {
		// lock the mutex
		pthread_mutex_lock(&m);
		count++;
		printf("incr: %d\n", count);
		// unlock the mutex
		pthread_mutex_unlock(&m);
		sleep(1);
	}
	return  0;	
}

void* decr_thread_func(void *param) {
	int i;
	for(i=1; i<=10; i++) {
		// lock the mutex
		pthread_mutex_lock(&m);
		count--;
		printf("decr: %d\n", count);
		// unlock the mutex
		pthread_mutex_unlock(&m);
		sleep(1);
	}
	return  0;	
}

int main() {
	pthread_t t1, t2;
	int i, ret;
	// create mutex (with default attribs=NULL)
	pthread_mutex_init(&m, NULL);
	ret = pthread_create(&t1, NULL, incr_thread_func, NULL);
	ret = pthread_create(&t2, NULL, decr_thread_func, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("final count: %d\n", count);
	// destroy mutex
	pthread_mutex_destroy(&m);
	return 0;
}


// terminal> gcc thread4.c -o thread.out -lpthread
// terminal> ./thread.out



            

