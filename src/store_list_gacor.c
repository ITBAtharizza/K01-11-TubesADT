#include <stdio.h>
#include "listdin.h"

void OptimizeStoreList(ListDin *store) {
    if (IsEmptyListDin(*store)) {
        printf("Toko kosong. Tidak ada yang bisa dioptimalkan.\n");
        return;
    }
    ReverseListDin(store);
    printf("Daftar barang di toko telah dioptimalkan (dibalik urutannya).\n");
    printf("Berikut barang setelah dioptimalkan:\n");
    PrintListDin(*store);
}
