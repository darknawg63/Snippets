#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
  int temp;
  char name[BUFSIZ];

  printf ("Input your number: ");

  while (scanf("%d", &temp) != 1)
    {
      while (getchar() != '\n');
      printf ("Try again: ");
    }

  printf ("You entered %d\n", temp);

  // If user entered some trash after the integer like 14EWZ
  // Consume all the offensize trailing output to clear the buffer
  while (fgetc(stdin) != '\n') // Read until a newline is found
             ;

  //fgets(name, BUFSIZ, stdin);
  //printf ("Trailing trash input %s\n", name);

  return(0);
}

