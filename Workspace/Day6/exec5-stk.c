#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char cmd[512], *ptr, *args[32];
	int i, ret, err, s;

	while(1) {
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

		//for(i=0; args[i]!=NULL; i++)
		//	puts(args[i]);
		
		if(strcmp(args[0], "exit") == 0 || strcmp(args[0], "bye") == 0)
			_exit(0);
		else if(strcmp(args[0], "cd") == 0)
			chdir(args[1]);
		else {
			ret = fork();
			if(ret == 0) {
				err = execvp(args[0], args);
				if(err < 0) {
					perror("bad command");
					_exit(1);
				}
			} 
			else
				wait(&s);
		}
	}
	return 0;
}



            
