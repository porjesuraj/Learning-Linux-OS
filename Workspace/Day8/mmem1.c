#include <stdio.h> 
#include <stdlib.h> 

int main() {

unsigned long i,size = 1 * 1024 * 1024 * 1024; 
char *p = (char*) malloc(size); 
printf("addr: %p \n",p);
getchar();
for(i=0;i<size;i = i + 4096) {

*(p + i) = 'A'; 
}
printf("physical mem allocated \n " ); 
getchar(); 
free(p); 

return 0; 
}
