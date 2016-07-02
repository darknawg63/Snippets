#include <stdio.h>
#include <string.h>

int
main (void)
{
  FILE *fp;
  char name[30];
  fp = fopen("myfile.txt", "r");
  rewind(fp);
  fread(name, sizeof(name), 1, fp);
  printf("Name found %s\n", name);
  fclose(fp);

}
