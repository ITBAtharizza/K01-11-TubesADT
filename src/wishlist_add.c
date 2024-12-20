#include "wishlist_add.h"
#include <stdio.h>

void WishlistAdd(List *L, ListDin arr) {
    Word itemName;

    printf("Masukkan nama barang: ");
    STARTWORD(NULL);
    itemName = currentWord;
    
    int index = IdxMemberListDin(arr, itemName);

    if (index == -1) {
        printf("Tidak ada barang dengan nama ");
        for (int i = 0; i < itemName.Length; i++) {
            printf("%c", itemName.TabWord[i]);
        }
        printf("!\n");
    } else {
        LinkedList *wishlist = &L->wishlist; 
        Barang item = makeBarang(arr.A[index].price, itemName);
        if (SearchLinkedList(L->wishlist, &item)) {
            printf("%s sudah ada di wishlist!\n", item.name);
        } else {
            InsVLastLinkedList(L->wishlist, &item);
            printf("Berhasil menambahkan %s ke wishlist!\n", item.name);
        }
    }
}