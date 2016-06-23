
#include <stdio.h>

int 
main(int argc, char *argv[])
{
  // create two arrays we care about
  int ages[] = {23, 43, 12, 89, 2};
  // pointer of array to arrays because 
  // each name is an array of characters
  char *names[] = {
      "Alan", "Frank",
      "Mary", "John", "Lisa"
  };

  printf("names[0] %c\n", names[0][0]);

  return (0);
}
