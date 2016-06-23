// fgets.c
#include <stdio.h>
#define MSG "Enter your name."
#define MAXLENGTH 79

int
main(void)
{
  char words[MAXLENGTH];
  puts(MSG);
  fgets(words, MAXLENGTH, stdin);
  printf("Your name is %s\n", words);
  return 0;
}
