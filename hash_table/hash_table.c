#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TAB 512

typedef struct Record
{
  char* key;
}Record;

unsigned int h1 (char* k);
unsigned int h2 (char* k);
unsigned int hash (char* k, int i);
unsigned int locate (Record hashtab[], char* k);
int member (Record hashtab[], char* k);
char* cpy (char* s);
int insert (Record hashtab[], char* k);
void init_hash_table (Record hashtab[]);

int
main (void)
{
  FILE *fp;

  char* strings[] = {
      "grape",
      "cherry",
      "orange",
      "grape",
      "apple"
  };

  Record hashtab[HASH_TAB];
  size_t i;
  size_t n = sizeof(strings) / sizeof(char*);
  init_hash_table(hashtab);

  for (i = 0; i < n; i++)
    if (!member(hashtab, strings[i]))
      insert(hashtab, strings[i]);
    else
      {
        printf("Duplicate %s\n", strings[i]);
        break;
      }
  fp = fopen("hash.txt", "w");
  fwrite(hashtab, sizeof(hashtab), 1, fp);
  fclose(fp);

  for ( int j = 0; j < HASH_TAB; j++)
    printf("hashtab %u\n", hashtab[j].key);
  printf("locate cherry %u\n", locate(hashtab, "cherry"));
  printf("cherrys key is %u\n", hashtab[269].key);

}

unsigned int
h1 (char* k)
{
  unsigned int h;
  unsigned char *c;

  h = 0;

  /*
   *  We cast the string to an unsigned string;
   *  As long as c is something;
   *  Increment the pointer so that we can dereference the next char
   *
   */
  for (c = (unsigned char *) k; *c; c++)
    h = h * 37 + *c;
  return h;
}

unsigned int
h2 (char* k)
{
  unsigned int h;
  unsigned char *c;

  h = 0;

  /*
   *  We cast the string to an unsigned string;
   *  As long as c is something;
   *  Increment the pointer so that we can dereference the next char
   *
   */
  for (c = (unsigned char *) k; *c; c++)
    h = h * 31 + *c; // we use a different prime number than in h1()
  return h % 2 == 0 ? h + 1 : h;
}

unsigned int
hash (char* k, int i)
{
  return (h1(k) + i * h2(k)) % HASH_TAB;
}

unsigned int
locate (Record hashtab[], char* k)
{
  /*
   * "i" keeps track of how many buckets we have probed
   * "b" stores address of the current bucket
   */
  unsigned int i, b;

  for (i = 0; i < HASH_TAB; i++)
    {
      b = hash(k, i);

      if (NULL == hashtab[b].key ||
          strcmp(hashtab[b].key, k) == 0)
        break;
    }
  return b;
}

int
member (Record hashtab[], char* k)
{
  unsigned int b = locate(hashtab, k);

  if (NULL == hashtab[b].key)
    return 0;
  else
    return strcmp(hashtab[b].key, k) == 0;
}

    char*
    cpy (char* s)
    {
      char *dest, *d;

      d = dest = malloc(strlen(s) * sizeof(char) + 1);

      if (d)
        while ((*d++ = *s++));
      return dest;
    }

int
insert (Record hashtab[], char* k)
{
  unsigned int b;

  b = locate(hashtab, k);

  if (NULL == hashtab[b].key)
    {
      hashtab[b].key = cpy(k);
      return 1;
    }
  else
    return strcmp(hashtab[b].key, k) == 0;
}

void
init_hash_table (Record hashtab[])
{
  unsigned int b;

  for (b = 0; b < HASH_TAB; b++)
    hashtab[b].key = NULL;
  printf("key is %u\n", hashtab[b - 1].key);
}
