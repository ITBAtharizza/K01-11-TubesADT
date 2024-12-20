#include "store_list_gacor.h"
#include <stdio.h>

void StoreListGacor(ListDin *store) {
    if (IsEmptyListDin(*store)) {
        printf("TOKO KOSONG!\n");
    } else {
        printf("ISI TOKO:\n");
        printf("============================================================\n");
        printf("| %-3s | %-50s | %-10s |\n", "No", "Nama Barang", "Harga");
        printf("============================================================\n");

        for (int i = 0; i < store->Neff; i++) {
            printf("| %-3d | %-50s | %-10d |\n", i + 1, store->A[i].name, store->A[i].price);
        }

        printf("============================================================\n");
    }
}
