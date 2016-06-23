#include <stdio.h> 
#include <stdlib.h> 

#define MAX_SIZE 50

int 
main(void)
{
  char buf[BUFSIZ];
  char name[BUFSIZ];
  int i, x;
  int status;

  printf ("Enter your number: ");

  for ( i = 0; i < 5; i++)
    {
      if (status = fgets(buf, sizeof(buf), stdin) != NULL)
        {
          x = atoi(buf);
          printf ("You entered %d\n", x);
        }
    }  

  fgets(name, BUFSIZ, stdin);
  printf ("Trailing trash input %s\n", name);

  return(0);
}
