#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks(){
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
       while (currentChar == BLANK || currentChar == ENTER){
        ADV(); // Maju ke karakter berikutnya
    }
}

void STARTWORD(char *filename){
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(filename);
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == ENTER){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
     if (isEndWord()) {
        return;
    }

    IgnoreBlanks();
    if (currentChar == MARK || currentChar == ENTER) {
        endWord = true;
        return;
    }

    CopyWord();
    IgnoreBlanks();
}

void CopyWord(){
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    for (int i = 0; i < NMax; i++){
        currentWord.TabWord[i] = '\0';
    }
    
    while (currentChar != BLANK && currentChar != MARK && currentChar != ENTER){
        if (currentWord.Length < NMax){
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else{
            break;
        }
    }
    
    if (currentChar == MARK || currentChar == ENTER){
        endWord = true;
    }
}

boolean isEndWord(){
    return endWord;
}