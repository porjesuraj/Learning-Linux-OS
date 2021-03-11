#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;

void* incr_thread_func(void *param) {
	int i;
	for(i=1; i<=10; i++) {
		count++;
		printf("incr: %d\n", count);
		sleep(1);
	}
	return  0;	
}

void* decr_thread_func(void *param) {
	int i;
	for(i=1; i<=10; i++) {
		count--;
		printf("decr: %d\n", count);
		sleep(1);
	}
	return  0;	
}

int main() {
	pthread_t t1, t2;
	int i, ret;
	ret = pthread_create(&t1, NULL, incr_thread_func, NULL);
	ret = pthread_create(&t2, NULL, decr_thread_func, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("final count: %d\n", count);
	return 0;
}


// terminal> gcc thread4.c -o thread.out -lpthread
// terminal> ./thread.out



            
