#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  char strCoordinates[101];
  char *ptr;
  int coordinates[4];
  while(fgets(strCoordinates, sizeof(strCoordinates), stdin) != NULL) 
    {
      char *s = strCoordinates;
      for (int x = 0; x < 4; x++) 
        {
          coordinates[x] = strtol(s, &ptr, 10);
          s = ptr;
        }
      printf("%d,%d,%d,%d\n", coordinates[0],coordinates[1],coordinates[2],coordinates[3]);
    }
}

