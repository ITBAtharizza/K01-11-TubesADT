#include <stdio.h>
#include "fungsi.h"
#include "supply.h"

void Supply(Queue *antrian, ListDin *list_barang){
    Word val;
    dequeue(antrian, &val);
    printf("Apakah kamu ingin menambahkan barang %s: ", val.TabWord);
    STARTWORD(NULL);
    if (IsWordEqual(currentWord, "Terima")){
        printf("Harga barang: ");
        ADVWORD();
        int Harga = wordToInt(currentWord);
        if (Harga != -9999){
            Barang barang = makeBarang(Harga, val);
            InsertLastListDin(list_barang, barang);
            printf("\"%s\" dengan harga %d telah ditambahkan ke toko.\n", list_barang->A[list_barang->Neff-1].name, list_barang->A[list_barang->Neff-1].price);
        }
    }
    else if (IsWordEqual(currentWord, "Tunda")){
        enqueue(antrian, val);
        printf("\"%s\" dikembalikan ke antrian.\n", val);
    }
    else if (IsWordEqual(currentWord, "Tolak")){
        printf("\"%s\" dihapuskan dari antrian.\n", val);
    }
}
