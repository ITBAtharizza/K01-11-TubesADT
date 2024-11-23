#include <stdio.h>
#include "list.h"
#include "custom.h"

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
    User user1 = makeUser(1000, name1, password1);

    Word name2 = {"Athar", 5};
    Word password2 = {"67890", 5};
    User user2 = makeUser(1500, name2, password2);

    Word name3 = {"Atha", 4};
    Word password3 = {"abc123", 6};
    User user3 = makeUser(2000, name3, password3);

    /* Menambah elemen ke dalam list */
    InsertFirst(&L, user1);
    InsertLast(&L, user2);
    InsertLast(&L, user3);

    printf("Setelah penambahan elemen:\n");
    PrintList(L);

    /* Menyisipkan elemen di tengah */
    Word name4 = {"Kezia", 5};
    Word password4 = {"qwerty", 6};
    User user4 = makeUser(500, name4, password4);
    InsertAt(&L, user4, 1);

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
    InsertFirst(&L2, user4);  // Menambahkan user4 ke L2

    List L3 = Concat(L, L2);
    printf("Setelah menggabungkan list L dan L2:\n");
    PrintList(L3);

    return 0;
}
