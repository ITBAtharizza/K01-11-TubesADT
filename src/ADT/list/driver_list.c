#include <stdio.h>
#include "list.h"

void PrintList(List L) {
    int i;
    printf("List: ");
    for (i = FirstIdx(L); i <= LastIdx(L); i++) {
        printf("{%s, %s, %d} ", L.A[i].name, L.A[i].password, L.A[i].money);
    }
    printf("\n");
}

int main() {
    /* Membuat list */
    List L = MakeList();
    printf("List dibuat. Panjang list: %d\n", Length(L));

    /* Membuat beberapa user untuk mengisi list */
    Word name1 = {"Syasya", 6};
    Word password1 = {"12345", 5};
    LinkedList LL1;
    infotypeLL itemL1_1 = "Soto Ayam";
    infotypeLL itemL1_2 = "Nasi Goreng";
    infotypeLL itemL1_3 = "Bakso";
    infotypeLL itemL1_4 = "Mie Ayam";
    address P;
    CreateEmptyLinkedList(&LL1);
    InsVFirstLinkedList(&LL1, itemL1_1);
    InsVLastLinkedList(&LL1, itemL1_2);
    InsVLastLinkedList(&LL1, itemL1_3);
    InsVLastLinkedList(&LL1, itemL1_4);
    Stack Histori1;
    CreateEmptyStack(&Histori1);
    OneHistory his1_1 = {"Riwayat Pembelian Pertama", 100};
    OneHistory his1_2 = {"Riwayat Pembelian Kedua", 200};
    OneHistory his1_3 = {"Riwayat Pembelian Ketiga", 300};
    PushStack(&Histori1, his1_1);
    PushStack(&Histori1, his1_2);
    PushStack(&Histori1, his1_3);
    User user1 = makeUser(1000, name1, password1, Histori1, LL1);

    Word name2 = {"Athira", 6};
    Word password2 = {"67890", 5};
    LinkedList LL2;
    infotypeLL itemL2_1 = "Bakwan Jagung";
    infotypeLL itemL2_2 = "Salmon Sushi";
    infotypeLL itemL2_3 = "Iga Penyet";
    infotypeLL itemL2_4 = "Bubur Ayam";
    address P;
    CreateEmptyLinkedList(&LL2);
    InsVFirstLinkedList(&LL2, itemL2_1);
    InsVLastLinkedList(&LL2, itemL2_2);
    InsVLastLinkedList(&LL2, itemL2_3);
    InsVLastLinkedList(&LL2, itemL2_4);
    Stack Histori2;
    CreateEmptyStack(&Histori2);
    OneHistory his2_1 = {"Riwayat Pembelian Pertama", 200};
    OneHistory his2_2 = {"Riwayat Pembelian Kedua", 300};
    OneHistory his2_3 = {"Riwayat Pembelian Ketiga", 400};
    PushStack(&Histori2, his2_1);
    PushStack(&Histori2, his2_2);
    PushStack(&Histori2, his2_3);
    User user2 = makeUser(1500, name2, password2, Histori2, LL2);

    /* Menambah elemen ke dalam list */
    InsertFirst(&L, user1);
    InsertLast(&L, user2);

    printf("Setelah penambahan elemen:\n");
    PrintList(L);

    /* Menyisipkan elemen di tengah */
    Word name3 = {"Febri", 5};
    Word password3 = {"qwertyiuop", 10};
    LinkedList LL3;
    infotypeLL itemL3_1 = "Perkedel Kentang";
    infotypeLL itemL3_2 = "Ikan Pindang";
    infotypeLL itemL3_3 = "Telur Balado";
    infotypeLL itemL3_4 = "Es Teh";
    address P;
    CreateEmptyLinkedList(&LL3);
    InsVFirstLinkedList(&LL3, itemL3_1);
    InsVLastLinkedList(&LL3, itemL3_2);
    InsVLastLinkedList(&LL3, itemL3_3);
    InsVLastLinkedList(&LL3, itemL3_4);
    Stack Histori3;
    CreateEmptyStack(&Histori3);
    OneHistory his3_1 = {"Riwayat Pembelian Pertama", 300};
    OneHistory his3_2 = {"Riwayat Pembelian Kedua", 500};
    OneHistory his3_3 = {"Riwayat Pembelian Ketiga", 600};
    PushStack(&Histori3, his3_1);
    PushStack(&Histori3, his3_2);
    PushStack(&Histori3, his3_3);
    User user3 = makeUser(2500, name2, password2, Histori3, LL3);
    InsertAt(&L, user3, 1);

    printf("Setelah menyisipkan elemen di tengah:\n");
    PrintList(L);

    /* Menghapus elemen pertama */
    DeleteFirst(&L);
    printf("Setelah menghapus elemen pertama:\n");
    PrintList(L);

    /* Menghapus elemen terakhir */
    DeleteLast(&L);
    printf("Setelah menghapus elemen terakhir:\n");
    PrintList(L);

    /* Menghapus elemen di tengah */
    DeleteAt(&L, 1);
    printf("Setelah menghapus elemen di tengah:\n");
    PrintList(L);

    /* Mengecek apakah elemen tertentu ada di dalam list */
    if (Search(L, user2)) {
        printf("User2 ditemukan di dalam list.\n");
    } else {
        printf("User2 tidak ditemukan di dalam list.\n");
    }

    /* Menggabungkan dua list */
    List L2 = MakeList();
    InsertFirst(&L2, user3);  // Menambahkan user3 ke L2

    List L3 = Concat(L, L2);
    printf("Setelah menggabungkan list L dan L2:\n");
    PrintList(L3);

    return 0;
}
