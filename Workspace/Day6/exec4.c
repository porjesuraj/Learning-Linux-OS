#include <stdio.h> 
#include <string.h> 

int main(){
char cmd[512], *ptr;

printf("cmd> ");
	gets(cmd);
	
ptr = strtok(cmd, " " ); 
puts(ptr); 

do {

ptr = strtok(NULL, " " ); 
puts(ptr); 

 } while(ptr != NULL);

return 0;

}
