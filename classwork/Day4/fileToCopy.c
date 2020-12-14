#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, fs;
	char buf[32];
	int cnt;

	//0. check number of command line args
	if(argc != 3) {
		printf("invalid arguments.\n");
		return 1;
	}

	//1. open source file for reading
	fs = open(argv[1], O_RDONLY);
	if(fs < 0) {
		perror("open() failed to open source file");
		_exit(1);
	}
	//2. open destination file for writing
	fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if(fd < 0) {
		perror("open() failed to open destination file");
		_exit(1);	
	}
	//3. read few bytes from source file
	while( (cnt = read(fs, buf, sizeof(buf))) > 0 )
	{
		//4. write those bytes into destination file
		write(fd, buf, cnt);
	} //5. repeat steps 3 & 4 until end of source file

	//6. close destination file
	close(fd);
	//7. close source file
	close(fs);

	printf("file copied.\n");
	return 0;
}

//terminal> gcc -o filecopy.out filecopy.c
//terminal> ./filecopy.out ~/.bashrc copy.txt



            
