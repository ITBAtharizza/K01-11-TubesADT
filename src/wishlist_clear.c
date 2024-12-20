#include <stdio.h>
#include "linkedlist.h"

void ClearWishlist(LinkedList *wishlist) {
    infotypeLL temp;
    while (!IsEmptyLinkedList(*wishlist)) {
        DelVFirstLinkedList(wishlist, &temp);
    }
    printf("Wishlist berhasil dikosongkan.\n");
}
