#ifndef __FUNGSI_H_
#define __FUNGSI_H_

#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"
#include "custom.h"
#include "list.h"
#include "listdin.h"

boolean IsWordEqual(Word word, char *reference);
int wordToInt(Word word);
void goodsWithManyWords(char **goods, int *length, Word word);

#endif