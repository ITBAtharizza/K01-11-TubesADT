#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"

int main(){
    char filename[50];
    printf("Masukkan perintah:  ");
    STARTWORD(NULL);

    if (IsWordEqual(currentWord, "LOAD")){
        ADVWORD();
        for (int i = 0; i < currentWord.Length; i++){
            filename[i] = currentWord.TabWord[i];
        }
        filename[currentWord.Length] = '\0';
        Load(filename);
    }
}