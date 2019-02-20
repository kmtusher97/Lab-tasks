#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[1000];

int main( int arg, char* args[] )
{
  if( args[1][0] == '>' )
  {
    FILE* f;
    f = fopen(strcat(args[2], ".txt"), "w");
    if( f == NULL )
    {
      printf("Error!!\n");
      exit(-1);
    }

//    while( gets(s) )
//    {
//      printf(">> %s\n", s);
//      fprintf(f, "%s", s);
//    }

    printf("\nFile Created\n");
    fclose(f);
  }
  else
  {

  }
  return 0;
}
