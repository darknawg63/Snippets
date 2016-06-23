#include <stdio.h>

#define MAXLEN 4 // Want 15 characters but must account for \0 terminator
#define FALSE 0
#define TRUE !FALSE

int top = -1;
void push(char *stack);
void pop(char *stack);
int empty(char* stack);
int arePair(char opening, char closing);
void display(char* stack);

int
main(void)
{
  char a[MAXLEN];
  a[0] = 0;
  puts("Enter term:");
  //push(a);
  //pop(a);
  //push(a);
  display(a);
  printf("Empty status %d\n", empty(a));
  printf("\nare pair %d\n", arePair(a[0], a[1]));

  return 0;
}

void
push(char *stack)
{
  char ch;

  while ( top != MAXLEN - 1)
    {
      scanf(" %c", &ch);
      stack[++top] = ch;
    }
  return;
}

void
pop(char* stack)
{
  --top;
}

int
empty(char* stack)
{
  if (stack[0] == 0)
    return TRUE;
  else
    return FALSE;
}

int
arePair(char opening,char closing)
{
  if(opening == '(' && closing == ')') return TRUE;
  else if(opening == '{' && closing == '}') return 1;
  else if(opening == '[' && closing == ']') return 1;
  return 0;
}

void display(char* stack)
{
    for ( int i = top; i >= 0; i--)
    {
      printf("%c ", stack[i]);
    }
}
