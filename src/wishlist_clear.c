#include "wishlist_clear.h"

void WishlistClear(LinkedList *wishlist) {
    if (IsEmptyLinkedList(*wishlist)){
        printf("Wishlist Kosong!\n");
        return;
    }
    infotypeLL temp;
    while (!IsEmptyLinkedList(*wishlist)) {
        DelVFirstLinkedList(wishlist, &temp);
    }
}
