#include <stdio.h> 
#include <stdlib.h> 

/*
 *  An example of how to use strtol() to read a number
 *  and validate that one was entered correctly.
 *
 */

int main(void)
{
  char buf[BUFSIZ];
  char *p;
  long int i;

  printf ("Enter a number: ");

  if (fgets(buf, sizeof(buf), stdin) != NULL)
    {
      i = strtol(buf, &p, 10);

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

      if (buf[0] != '\n' && (*p == '\n' || *p == '\0'))
        printf ("Valid number of %ld entered\n", i); 
      else  printf ("Invalid number entered\n");
    }  

  return(0);
}
