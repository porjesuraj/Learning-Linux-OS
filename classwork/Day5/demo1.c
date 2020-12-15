#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc,char *argv[]) {
DIR *dp;
char *dirpath = ".";
struct dirent *ent;
if(argc == 2) {

dirpath = argv[1]; 

}

dp = opendir(dirpath);

if(dp == NULL) {
perror("cannot open dir");

exit(1); 
}

while ((ent = readdir(dp)) != NULL ) {
printf("%lu\t%s\n", ent->d_ino,ent->d_name);

} 


closedir(dp);

return 0; 




}

//> gcc -o dirlist.out dirlist.out  
// > ./dirlist.out /home/sunbeam
// > ./dirlist

