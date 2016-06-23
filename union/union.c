// Code sample from K & R Second Edition
#include <stdio.h>

int
main(void)
{
  union u_tag {
      int ival;
      float fval;
      char *sval;
  } u;

  union u_tag whatever;
  // June 16 2016 - JAW 
  // Only the last set variable in the union can be accessed.
  whatever.ival = 4400;
  whatever.sval = "what";

  printf("The value at whatever.sval is %s\n", whatever.sval);

  return (0);
}

