#include <stdio.h>
#include <stdlib.h>
#include "request.h"

void Request(Queue *antrian, ListDin *list_barang){
    printf("Nama barang yang diminta: ");
    STARTWORD(NULL);

    Word name;
    name.Length = 0;
    for (int i = 0; i < NMax; i++){
        name.TabWord[i] = '\0';
    }
    
    char *goods = malloc(1);
    if (goods == NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    goods[0] = '\0';
    int length = 0;

    goodsWithManyWords(&goods, &length, currentWord);
    while (true && !isEndWord()){
        ADVWORD();
        goodsWithManyWords(&goods, &length, currentWord);
    }

    if (length > 0 && goods[length - 1] == ' '){
        goods[length - 1] = '\0';
        length -= 1;
    }

    if (length > 50){
        length = 50;
    }

    for (int j = 0; j < length && j < 50; j++){
        name.TabWord[j] = goods[j];
    }            
    name.TabWord[length] = '\0';
    name.Length = length;
    free(goods);
    
    if (!IsMemberListDin(*list_barang, name)){
        if (!isMemberQueue(*antrian, name)){
            enqueue(antrian, name);
        }
    }
}