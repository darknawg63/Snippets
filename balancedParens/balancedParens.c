#include <stdio.h>
#include <string.h>

#define MAXLEN 101 // Want 15 characters but must account for \0 terminator
#define FALSE 0
#define TRUE !FALSE

char stack[MAXLEN] = {'\0'};
int top = -1;
void push(char ch);
void pop();
int isEmpty();
int arePair(char opening, char closing);
int areParanthesesBalanced();
void display();

int
main(void)
{
  puts("Enter term:");
  //push(a);
  //push(a);
  printf("match %d\n", areParanthesesBalanced());

  return 0;
}

void
push(char ch)
{
  stack[++top] = ch;
  printf("Top is %d\n", top);

  return;
}

void
pop()
{
  stack[top] = '\0';
  --top;
  printf("popped: top is %d\n", top);
}

int
isEmpty()
{
  if (stack[top] == '\0')
    return TRUE;
  else
    return FALSE;
}

int
arePair(char opening,char closing)
{
  if(opening == '(' && closing == ')') return TRUE;
  else if(opening == '{' && closing == '}') return TRUE;
  else if(opening == '[' && closing == ']') return TRUE;
  return FALSE;
}

int areParanthesesBalanced()
{
  char expr[MAXLEN];
  scanf(" %100[^\n]s", expr);
  printf("characters %c\n", expr[0]);
  for ( int i = 0; i < MAXLEN -1; i++)
    {
      if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        push(expr[i]);
      else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
          if(isEmpty() || !arePair(stack[top],expr[i]))
            return FALSE;
          else
            pop();
          if (isEmpty() && expr[i+1] == '\0')
            return TRUE;
        }
    }
  return isEmpty();
}

void display()
{
  for ( int i = top; i >= 0; i--)
    {
      printf("%c ", stack[i]);
    }
}
