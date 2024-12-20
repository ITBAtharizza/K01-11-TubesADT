#include <stdio.h>
#include "linkedlist.h"

void ClearWishlist(LinkedList *wishlist) {
    if (IsEmptyLinkedList(*wishlist)) {
        printf("Wishlist sudah kosong.\n");
        return;
    }
    infotypeLL temp;
    while (!IsEmptyLinkedList(*wishlist)) {
        DelVFirstLinkedList(wishlist, &temp);
    }
    printf("Wishlist berhasil dikosongkan.\n");
}
