#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXLEN 80

int
main (void)
{

  int i = 0;
  char *a;
  char *b;

  printf("Enter a string of text: ");
  scanf("%10[^\n]s", a);

  b = malloc(MAXLEN);
  memcpy(b, a, strlen(a));

  printf("Contents of array b is.\n");

  while ( b[i] != '\0')
    {
      printf("%c", b[i]);
      i++;
    }

  printf ("\nThe length of array b is %d\n", i);
  printf ("The strlen of array b is %d\n", strlen(b));
  printf ("a[7] is %c\n", a[7]);
  free(b);

  return (0);
}
