#include <stdio.h>   

int main(void)
{
  int i;
  char name[BUFSIZ];

  printf ("Input a number: ");
  scanf("%d", &i);

  printf("Enter your name: ");
  fgets(name, BUFSIZ, stdin);

  printf ("Hello %s, your number was %d\n", name, i);

  return(0);
}

/*
 *  * Program output:
 *   Input a number: 9898
 *    Enter your name: 
 *     Hello 
 *      , your number was 9898
 *       *
 *        */
