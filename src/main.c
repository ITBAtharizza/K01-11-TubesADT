#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"
#include "custom.h"
#include "list.h"
#include "listdin.h"
#include "load.h"

int main(){
    char filename[50];
    printf("Masukkan perintah:  ");
    STARTWORD(NULL);
    List list_user;
    ListDin list_barang;

    if (IsWordEqual(currentWord, "LOAD")){
        ADVWORD();
        for (int i = 0; i < currentWord.Length; i++){
            filename[i] = currentWord.TabWord[i];
        }
        filename[currentWord.Length] = '\0';
        Load(filename, &list_user, &list_barang);
        for (int i = 0; i < LengthListDin(list_barang); i++){
            printf("Harga: %d, Nama: %s\n", list_barang.A[i].price, list_barang.A[i].name);
        }
        for (int i = 0; i < Length(list_user); i++){
            printf("Uang: %d, Nama: %s, Password: %s\n", list_user.A[i].money, list_user.A[i].name, list_user.A[i].password);
        }
    }
    else if (IsWordEqual(currentWord, "LOGIN")){
        printf("1");
    }

}