#include <stdio.h> 
#include <unistd.h> 
#include <signal.h> 

// signal handling demo 

// step !: implement signal handler function 
void sigint_handler(int sig) {
printf("signal is caught : %d \n", sig); 

}
int main() {

int i = 0; 
////step2: register signal handler (in signal handler table of current process).
signal(SIGINT,sigint_handler); 
while(1)
{
printf("loop %d \n", i); 
i++;

sleep(2); 
}

}

//terminal 1> gcc -o signal.out signal1.c
//terminal 1> ./signal.out 

// ctrl + C

//terminal 2> pkill -2 signal.out



