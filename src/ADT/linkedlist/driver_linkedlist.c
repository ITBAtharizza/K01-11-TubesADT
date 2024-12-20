#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    // Inisialisasi LinkedList dan isi LinkedList
    LinkedList L;
    infotypeLL item1 = "Soto Ayam";
    infotypeLL item2 = "Nasi Goreng";
    infotypeLL item3 = "Bakso";
    infotypeLL item4 = "Mie Ayam";
    infotypeLL removedItem;
    address P;

    // Membuat LinkedList Kosong
    CreateEmptyLinkedList(&L);

    // Menambahkan item ke LinkedList
    InsVFirstLinkedList(&L, item1);
    InsVLastLinkedList(&L, item2);
    InsVLastLinkedList(&L, item3);
    InsVLastLinkedList(&L, item4);

    // Print hasil LinkedList
    printf("Isi LinkedList:\n");
    PrintInfoLinkedList(L);

    // Search item di LinkedList
    P = SearchLinkedList(L, item2);
    if (P != NilLL) {
        printf("\nItem '%s' ditemukan di LinkedList.\n", Info(P));
    } else {
        printf("\nItem '%s' tidak ditemukan di LinkedList..\n", item2);
    }

    // Menghapus Item Pertama dari LinkedList
    DelVFirstLinkedList(&L, &removedItem);
    printf("\nLinkedList setelah menghapus first item ('%s'):\n", removedItem);
    PrintInfoLinkedList(L);

    // Menghapus Item Terakhir dari LinkedList
    DelVLastLinkedList(&L, &removedItem);
    printf("\nLinkedList setelah menghapus last item ('%s'):\n", removedItem);
    PrintInfoLinkedList(L);

    // Menghapus Item Spesifik dari LinkedList
    DelPLinkedList(&L, item3);
    printf("\nLinkedList setelah menghapus item ke-3 '%s':\n", item3);
    PrintInfoLinkedList(L);

    // Menghapus seluruh Item dari LinkedList
    while (!IsEmptyLinkedList(L)) {
        DelVFirstLinkedList(&L, &removedItem);
    }
    printf("\nAfter clearing the linked list:\n");
    if (IsEmptyLinkedList(L)) {
        printf("The linked list is now empty.\n");
    }

    return 0;
}
