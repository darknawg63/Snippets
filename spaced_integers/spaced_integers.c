#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  char buf[101];
  char *ptr;
  int x;
  int integers[4];

  if (fgets(buf, sizeof(buf), stdin) != NULL)
    {
      char *s = buf;

      /*
       *  If the first character of the buffer is \n, the user 
       *  pressed [Enter] with entering any text at all, which
       *  is therefore invalid.
       *  
       *  The pointer p has been updated by strtol() to point to
       *  the first invalid character after the number.  
       *  If this character is \0 it means we reached the end of
       *    the array successfully, so we received a good number.
       *  If this character is \n it also means we reached the
       *    end of the input successfully.  This is a symptom of
       *    using fgets() to obtain the string, but does not 
       *    represent a problem.
       *  If this character is anything else, it means there was
       *    some additional characters entered after the number.
       *    In this sample program, I have deemed this situation
       *    to be invalid, however, in your program it may be 
       *    valid, depending on what you're expecting from the user. 
       *
       */

      if (buf[0] != '\n' && (*ptr == '\n' || *ptr == '\0'))
        {
          while (x < 4)
            {
              integers[x++] = strtol(s, &ptr, 10);
              s = ptr;
            }
        }

      else
        {
          printf ("Invalid number entered\n");
          return 1;
        }
    }

  printf("%d %d %d %d\n", integers[0],integers[1],integers[2],integers[3]);
  return 0;
}

