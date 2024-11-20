#ifndef __FUNGSI_H_
#define __FUNGSI_H_

#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "datatype.h"

boolean IsWordEqual(Word word, char *reference);
int wordToInt(Word word);
void goodsWithManyWords(char **goods, int *length, Word word);


void Load(char *filename);

#endif