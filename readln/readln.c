#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 20
#define EMPTY 0

int GetInt (char str[], long int* int_, int capacity);

int
main (void)
{
  char input[CAPACITY];
  long int num;
  int noinput = EMPTY;

  while (noinput == EMPTY)
    {
      printf("number: ");
      noinput = GetInt(input, &num, CAPACITY);
    }
  printf("You entered %ld\n", num);
  return 0;
}

int
GetInt (char str[], long int* int_, int capacity)
{
  char ch;
  char* p;
  int i;
  int in_buffer;
  i = 0;
  in_buffer = 1;
  while (in_buffer)
    {
      ch = getchar();
      if ((ch == '\n') || (ch == EOF))
        {
          in_buffer = 0;
        }
      else
        if (i < capacity - 1)
          {
            str[i] = ch;
            i++;
          }
    }
  str[i] = '\0';
  *int_ = strtol(str, &p, 10);
  if (str[0] != '\n' && i != 0 && (*p == '\n' || *p == '\0'))
    return i - i + 1; // Always return 1
  else
    return i - i; // Always return 0
  return i;
}
