#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n;
  printf("Enter size of array ");
  scanf("%d", &n);

  int *b;
  b = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
      b[i] = i * 4;
  }

  printf("Value of b[3] is %d\n", b[3]);

  return 0;
}
