#include "cartadd.h"

void cartadd(ListDin List_Items, Map Cart, Barang Barang, int Banyak) {
    if (SearchListDin(List_Items, Barang) == -1) {
        printf("Barang tidak ada di toko!\n");
    } else {
        if (Banyak == 0) {
            printf("Jumlah barang yang dimasukkan ke dalam cart tidak bisa 0!\n");
        } else if (Banyak < 0) {
            printf("Barang yang dimasukkan ke dalam keranjang harus berjumlah positif!\n");
        } else {
            InsertMap(&Cart, Barang.name, Banyak);
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", Banyak, Barang.name);
        }
    }
}