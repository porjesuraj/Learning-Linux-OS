#include <stdio.h>
#include <unistd.h> 
#include <fcntl.h>

int main(int arg,char *argv[]) {
int fd,fs;
char buf[32]; 
int cnt;
// 0. check number of commands line args
if(argc != 3) {

print("invalid agruments \n");
return 1; 

}

//1.  open source file for reading 
fs = open(argv[1], O_RDONLY); 

if(fs < 0) {
print("failed to open source file ");
_exit(1); 
}

//2.  open destination file for writing 
// 0644: mode for file ,octal no , wrx
fd =  open(argv[2],O_WRONLY | O_TRUNC | O_CREAT, 0644); 
if(fd < 0) {
perror("open failed to open destiation failed "); 
}
 
//3.  read few bytes from source file
while( ( cnt = read(fs,buf,sizeof(buf))) > 0 )
{
//4.  write those bytes into destination file
write(fd,buf,cnt); 
}
//5.  repeat steps 3 and 4 until end of source file 
close(fd); 
// 6.close destination file 
close(fs); 
//7.  close source file

print("five copied"); 
return 0; 
}
// > gcc -o filecopy.out filecopy.c
// > ./filecopy.out ~/.bashrc copy.txt 

