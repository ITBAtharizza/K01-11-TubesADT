#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"
#include "custom.h"
#include "list.h"
#include "listdin.h"

boolean IsWordEqual(Word word, char *reference){
    int length = 0;
    while (reference[length] != '\0'){
        length++;
    }

    if (word.Length != length){
        return false;
    }

    for (int i = 0; i < word.Length; i++){
        if (word.TabWord[i] != reference[i]){
            return false;
        }
    }

    return true;
}

int wordToInt(Word Kata){
    int integer = 0;
    for (int i = 0; i < Kata.Length; i++){
        integer *= 10;
        integer += Kata.TabWord[i] - '0';
    }
    return integer;
}

void goodsWithManyWords(char **goods, int *length, Word currentWord){
    *goods = realloc(*goods, (*length + currentWord.Length + 2) * sizeof(char));
    if (*goods == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < currentWord.Length; i++){
        (*goods)[*length + i] = currentWord.TabWord[i];
    }
    *length += currentWord.Length;

    (*goods)[*length] = ' ';
    *length += 1;

    (*goods)[*length] = '\0';
}
