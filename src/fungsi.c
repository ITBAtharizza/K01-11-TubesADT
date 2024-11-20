#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"
#include "custom.h"

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

void Load(char *filename){
    STARTWORD(filename);
    
    if (IsEOP()){
        return;
    }

    int jumlah_barang = wordToInt(currentWord);

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
        printf("Barang: %s, Harga: %d\n", barang.name, barang.price);
        free(goods);
    }

    ADVWORD();
    int jumlah_user = wordToInt(currentWord);
    User users[100];

    for (int i = 0; i < jumlah_user; i++){
        ADVWORD();
        int money = wordToInt(currentWord);

        ADVWORD();
        Word name = currentWord;
        
        ADVWORD();
        Word password = currentWord;

        User user = makeUser(money, name, password);
        printf("Uang: %d, Nama: %s, Password: %s\n", user.money, user.name, user.password);
    }
}


