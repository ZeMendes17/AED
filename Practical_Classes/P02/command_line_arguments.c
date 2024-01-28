//
// Tomás Oliveira e Silva, AED, October 2021
//
// list all command line arguments
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[argc]) // argv is an array that has argc elements
// argc >> arg count
// string array that stores argc
{
  int val;
  for(int i = 0;i < argc;i++){
    printf("argv[%2d] = \"%s\"\n",i,argv[i]);
    val = atoi(argv[i]);
    printf("%d\n", val);
  }
  return 0;
}
