#include <stdio.h> 
#include <unistd.h>
#include <pthread.h> 

void* print_table(void *param) {
long i , num = (long) param; 

for (i = 1;i<=10; i++) {
printf("%ld * %ld = %ld \n", num,i, num * 1); 

sleep(1); 
}

return 0; 

}


int main() {

pthread_t t1,t2,t3;
pthread_create(&t1,NULL,print_table,(void*)10); 

pthread_create(&t2,NULL,print_table,(void*)20);


pthread_create(&t3,NULL,print_table,(void*)30); 
// calling thread i.e main will wait for completion of t1 thread abd will collect its return value 
pthread_join(t1,NULL); 

pthread_join(t2,NULL); 

pthread_join(t3,NULL); 

printf("bye! \n "); 
return 0;
}
