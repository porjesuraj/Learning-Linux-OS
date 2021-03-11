#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h> 

// fixed signature for thread fucntion
void* first_thread_function(void *param) {
int i; 
for(i=1; i<=60;i++) {
printf("first : %d \n",i); 
sleep(1); 
}
return 0; 
}


void* second_thread_function(void *param) {
int i; 
for(i=1; i<=60;i++) {
printf("second : %d \n",i); 
sleep(1); 
}
return 0; 
}


int main() {

pthread_t t1,t2; 
int i,ret; 

ret = pthread_create(&t1,NULL,first_thread_function,NULL); 

ret = pthread_create(&t2,NULL,second_thread_function,NULL); 

for(i=1; i <= 60; i++) {

printf("main %d \n ",i);  
sleep(1); 

}



return 0;
}
