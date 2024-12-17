#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"


void CartRemove(Map *M, keytype k, valuetype n) {
    if (!IsMemberMap(*M, k)) {
        printf("Barang tidak ada di keranjang belanja!\n");
        return;
    }

    valuetype currentQuantity = ValueMap(*M, k);

    if (currentQuantity < n) {
        printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", currentQuantity, k);
        return;
    }

    // Reduce quantity
    for (int i = 0; i < M->Count; i++) {
        if (M->Elements[i].Key == k) {
            M->Elements[i].Value -= n;
            // Remove the item if the quantity becomes zero
            if (M->Elements[i].Value == 0) {
                DeleteMap(M, k);
            }
            break;
        }
    }

    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", n, k);
}
