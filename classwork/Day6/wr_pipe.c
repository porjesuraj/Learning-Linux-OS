#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fw;
	char str[40];
	
	printf("WR: opening fifo.\n");
	fw = open("./myfifo", O_WRONLY);
	if(fw < 0) {
		perror("failed to open fifo");
		_exit(1);
	}

	printf("WR: enter a string: ");
	scanf("%s", str);

	write(fw, str, sizeof(str));
	printf("WR: data is sent.\n");

	close(fw);
	return 0;
}


           
