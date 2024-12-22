#include "wishlist_swap.h"
#include <stdio.h>
#include <stdlib.h>

void WishlistSwap(LinkedList *wishlist, int i, int j) {
    if (i <= 0 || j <= 0 || i > NbElmtLinkedList(*wishlist) || j > NbElmtLinkedList(*wishlist)) {
        printf("Gagal menukar posisi! Indeks tidak valid.\n");
        return;
    }

    if (i == j) {
        printf("Tidak ada perubahan, posisi yang dipilih sama.\n");
        return;
    }

    // Cari elemen pada posisi i dan j
    address p1 = First(*wishlist);
    address p2 = First(*wishlist);
    int count = 1;

    while (count < i && p1 != NilLL) {
        p1 = Next(p1);
        count++;
    }

    count = 1;
    while (count < j && p2 != NilLL) {
        p2 = Next(p2);
        count++;
    }

    if (p1 == NilLL || p2 == NilLL) {
        printf("Gagal menukar posisi! Salah satu elemen tidak ditemukan.\n");
        return;
    }

    // Tuker informasi pada elemen p1 dan p2
    infotypeLL temp = Info(p1);
    Info(p1) = Info(p2);
    Info(p2) = temp;

    printf("Berhasil menukar posisi barang pada indeks %d dengan indeks %d.\n", i, j);
}