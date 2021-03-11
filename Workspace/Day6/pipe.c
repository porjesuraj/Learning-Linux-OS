#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int ret, s;
	int arr[2];

	// create pipe
	ret = pipe(arr);
	if(ret < 0) {
		perror("pipe() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child -- sender
		char str1[32];

		// close read end
		close(arr[0]);

		printf("child: enter a string: ");
		scanf("%s", str1);
		printf("child: sending message ...\n");
		// send data in the pipe.
		write(arr[1], str1, sizeof(str1));
		
		// close pipe write end
		close(arr[1]);
	}
	else {
		// parent -- receiver
		char str2[32];
		
		// close write end
		close(arr[1]);
		
		printf("parent: waiting for child message.\n");
		// receive message from pipe.
		read(arr[0], str2, sizeof(str2));
		printf("parent: received %s", str2);

		wait(&s);

		// close pipe read end
		close(arr[0]);
	}
	return 0;
}



            
