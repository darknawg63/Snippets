#include <stdio.h>
#include "flush_input.h"


/*
 *flush_input()
 *
 *Used after a call to fgets to clear any characters
 *that may be still hanging around in the buffer for stdin
 */

void
flush_input ()
{
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
}
