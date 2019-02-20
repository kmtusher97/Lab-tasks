#include <stdio.h>
#include <stdlib.h>

int main( int arg, char* args[] )
{
  if( !strcmp(args[1], "ls") )
  {
    system(args[1]);
  }

  return 0;
}
