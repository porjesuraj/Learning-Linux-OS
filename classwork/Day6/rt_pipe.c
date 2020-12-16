#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fr;
	char str[40];
	
	printf("RD: opening fifo.\n");
	fr = open("./myfifo", O_RDONLY);
	if(fr < 0) {
		perror("failed to open fifo");
		_exit(1);
	}

	printf("RD: waiting for data...\n");
	read(fr, str, sizeof(str));

	printf("RD: data is received: %s.\n", str);

	close(fr);
	return 0;
}

//terminal> gcc -o rd_pipe.out rd_pipe.c 
//terminal> ./rd_pipe.out 


            
