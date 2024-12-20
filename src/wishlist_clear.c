#include "wishlist_clear.h"

void ClearWishlist(LinkedList *wishlist) {
    infotypeLL temp;
    while (!IsEmptyLinkedList(*wishlist)) {
        DelVFirstLinkedList(wishlist, &temp);
    }
}
