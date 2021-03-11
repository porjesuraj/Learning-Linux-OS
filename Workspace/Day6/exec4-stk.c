#include <stdio.h>
#include <string.h>

int main() {
	char cmd[512], *ptr, *args[32];
	int i;
	
	printf("cmd> ");
	gets(cmd);
	i = 0;
	ptr = strtok(cmd, " ");
	//puts(ptr);
	args[i++] = ptr;

	do {
		ptr = strtok(NULL, " ");
		//puts(ptr);
		args[i++] = ptr;
	}while(ptr != NULL);

	for(i=0; args[i]!=NULL; i++)
		puts(args[i]);

	return 0;
}

