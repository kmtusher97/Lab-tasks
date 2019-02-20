#include <stdio.h>

int main( int argn, char* args[] ) 
{
	if( remove(args[1]) == 0 ) 
    printf("Delete Successful\n");
  else 
    printf("Delete Unsuccessful\n");

	return 0;  
}
