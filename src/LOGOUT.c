#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"
#include "custom.h"
#include "list.h"
#include "listdin.h"

// Fungsi untuk logout
void Logout(List *list_user, ListDin *list_barang) {
    // Dealokasi semua list dinamis dan statis
    for (int i = 0; i < Length(*list_user); i++) {
        free((*list_user).A[i].name);
        free((*list_user).A[i].password);
    }
    DeallocateListDin(list_barang); // List dinamis (list_barang)
    CreateList(list_user);         // Reset list statis (list_user)

    printf("Logout berhasil. Semua data telah dikembalikan ke kondisi awal.\n");
}

int main() {
    char filename[50];
    printf("Masukkan perintah:  ");
    STARTWORD(NULL);
    List list_user;        // List user statis
    ListDin list_barang;   // List barang dinamis

    CreateList(&list_user); // Inisialisasi list_user
    CreateListDin(&list_barang, 100); // Inisialisasi list_barang dengan kapasitas 100

    if (IsWordEqual(currentWord, "LOAD")) {
        ADVWORD();
        for (int i = 0; i < currentWord.Length; i++) {
            filename[i] = currentWord.TabWord[i];
        }
        filename[currentWord.Length] = '\0';

        Load(filename, &list_user, &list_barang);

        for (int i = 0; i < LengthListDin(list_barang); i++) {
            printf("Harga: %d, Nama: %s\n", list_barang.A[i].price, list_barang.A[i].name);
        }
        for (int i = 0; i < Length(list_user); i++) {
            printf("Uang: %d, Nama: %s, Password: %s\n", list_user.A[i].money, list_user.A[i].name, list_user.A[i].password);
        }
    }
    else if (IsWordEqual(currentWord, "HELP")) {
        printf("1\n");
    }
    else if (IsWordEqual(currentWord, "LOGOUT")) {
        Logout(&list_user, &list_barang); // Memanggil fungsi logout
    }
    else {
        printf("Perintah tidak dikenali.\n");
    }

    return 0;
}
