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
#include "login.h"
#include "storelist.h"
#include "queue.h"
#include "request.h"
#include "start.h"

int main(){
    char filename[50];

    List list_user;
    ListDin list_barang;
    Queue antrian;
    boolean log_stats = false;
    User logged_in;

    CreateQueue(&antrian);
    list_barang = MakeListDin();
    list_user = MakeList();

    while (1){
        printf("Masukkan perintah:  ");
        STARTWORD(NULL);
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

        if (IsWordEqual(currentWord, "LOGIN")){
            login(&log_stats, &list_user, &logged_in);
        }

        if (IsWordEqual(currentWord, "STORE")){
            ADVWORD();
            if (IsWordEqual(currentWord, "LIST")){
                displayList(&list_barang);
            }
            if (IsWordEqual(currentWord, "REQUEST")){
                Request(&antrian, &list_barang);
                displayQueue(antrian);
            }
        } 
        if (IsWordEqual(currentWord, "STARTGAME")) {
            STARTGAME();
            printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
        }
        printf("Current word: %s\n", currentWord.TabWord);
    }
    return 0;
}