#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int ret, err, s;
	printf("parent started.\n");
	ret = fork();
	if(ret == 0) {
		// cal -y 2020
		err = execl("/usr/bin/cal", "cal", "-y", "2020", NULL);
		if(err < 0) {
			perror("exec() failed");
			_exit(1);
		}
	}
	else {
		waitpid(ret, &s, 0);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}
	printf("parent completed.\n");
	return 0;
}

            
