#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFFERSENTENCE 1000

typedef struct wd{
  int amount;
  char word[255];
  int length;
}word;

int checkWord(word *setOfWord, int amountSetOfWord, char *word);
void sortSetOfWord(word *setOfWord, int amountSetOfWord);
void menu();
void writeToFile(word *setOfWord, int amountSetOfWord);
void showSetOfWord(word *setOfWord, int amountSetOfWord);
int addWord(word *setOfWord, int amountSetOfWord, char *word);