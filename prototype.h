#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFFERSENTENCE 1000

typedef struct wd{
  int amount;
  char word[255];
  int length;
}word;