#include <stdio.h>
#include <string.h>

#define MAXLEN 101 // Want 15 characters but must account for \0 terminator

typedef enum
{
  FALSE,
  TRUE
} bool;

char stack[MAXLEN] = {'\0'};
int top = -1;
void push(char ch);
void pop();
bool isEmpty();
bool arePair(char opening, char closing);
bool areParanthesesBalanced();
void display();

int
main(void)
{
  fputs("Enter an expression: ", stdout);

  if (areParanthesesBalanced())
    printf("All opening brackets are closed.");
  else
    printf("Not all opening brackets are closed");
  return 0;
}

void
push(char ch)
{
  stack[++top] = ch; return;
}

void
pop()
{
  stack[top] = '\0';
  --top;
}

bool
isEmpty()
{
  bool is_empty = TRUE;
  bool not_empty = FALSE;

  if (stack[top] == '\0')
    return is_empty;
  else
    return not_empty;
}

bool
arePair(char opening,char closing)
{
  bool is_matched = TRUE;
  bool not_matched = FALSE;

  if(opening == '(' && closing == ')') return is_matched;
  else if(opening == '{' && closing == '}') return is_matched;
  else if(opening == '[' && closing == ']') return is_matched;
  return not_matched;
}

bool
areParanthesesBalanced()
{
  char expr[MAXLEN];
  scanf(" %100[^\n]s", expr); // the [^\n] allows spaces to be picked up

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
