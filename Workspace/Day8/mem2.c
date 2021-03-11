# include <stdio.h> 


int main() 
{
// "" string went to RO data section 
char *p = "SUN"; 
// this write is protection fault, so runtime error 
*p = 'F'; 
puts(p); 
// cout <<p 
return 0; 
}
