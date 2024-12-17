#include "cartremove.h"

void cartremove(Map Cart, Barang Barang, int Banyak){
    if (!IsMemberMap(Cart, Barang.name)) {
        printf("Barang tidak ada di keranjang belanja!\n");
    } else {
        DeleteMap(&Cart, Barang.name);
        printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", Banyak, Barang.name);
    }
}
