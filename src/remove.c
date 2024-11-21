#include <stdio.h>
#include <string.h>
#include "remove.h"
#include "listdin.h"
#include "mesinkata.h"
#include <stddef.h>

#define IdxUndef -1

void removeItem(ListDin *list_barang) {
    char nama_barang[50];
    printf("Masukkan nama barang yang ingin dihapus: ");
    printf("berikut merupakan list barang: \n");
    PrintListDin(*list_barang);
    if (IsEmptyListDin(*list_barang)) {
        printf("Tidak ada barang yang bisa dihapus\n");
        return;
    }
    else {
        STARTWORD(NULL);
        for (int i = 0; i < currentWord.Length; i++) {
            nama_barang[i] = currentWord.TabWord[i];
        }
        nama_barang[currentWord.Length] = '\0';
        int idx = IdxUndef;
        for (int i = 0; i < LengthListDin(*list_barang); i++) {
            if (strcmp(nama_barang, list_barang->A[i].name) == 0) {
                idx = i;
                break;
            }
        }
        if (idx == IdxUndef) {
            printf("Barang tidak ditemukan\n");
        } else {
            DeleteAtListDin(list_barang, idx);
            printf("Barang berhasil dihapus\n");
        }
    }
}

// int main() {
//     ListDin list_barang = MakeListDin();
//     ElTypeBarang buku;
//     buku.price = 1000;
//     strcpy(buku.name, "Buku");
//     InsertAtListDin(&list_barang, buku, 0);

//     ElTypeBarang pensil;
//     pensil.price = 1050;
//     strcpy(pensil.name, "Pensil");
//     InsertAtListDin(&list_barang, pensil, 1);
//     removeItem(&list_barang);
//     PrintListDin(list_barang);
//     return 0;
// }