#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"
#include "custom.h"
#include "list.h"
#include "listdin.h"

void Load(char *filename, List *list_user, ListDin *list_barang){
    STARTWORD(filename);
    
    if (IsEOP()){
        return;
    }

    int jumlah_barang = wordToInt(currentWord);
    *list_barang = MakeListDin();

    for (int i = 0; i < jumlah_barang; i++){
        ADVWORD();
        int price = wordToInt(currentWord);
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

        while (true){
            ADVWORD();
            goodsWithManyWords(&goods, &length, currentWord);

            if (isEndWord()){
                break;
            }
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

        Barang barang = makeBarang(price, name);
        InsertLastListDin(list_barang, barang);
        free(goods);
    }

    ADVWORD();
    int jumlah_user = wordToInt(currentWord);
    *list_user = MakeList();

    for (int i = 0; i < jumlah_user; i++){
        ADVWORD();
        int money = wordToInt(currentWord);

        ADVWORD();
        Word name = currentWord;
        
        ADVWORD();
        Word password = currentWord;

        User user = makeUser(money, name, password);

        InsertLast(list_user, user);
    }
}