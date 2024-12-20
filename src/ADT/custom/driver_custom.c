#include <stdio.h>
#include <stdlib.h>
#include "custom.h"

int main() {
    printf("Membuat beberapa user dan barang\n");
    /* Membuat beberapa user */
    Word name1 = {"Syasya", 6};
    Word password1 = {"12345", 5};
    LinkedList L1;
    infotypeLL itemL1_1 = "Soto Ayam";
    infotypeLL itemL1_2 = "Nasi Goreng";
    infotypeLL itemL1_3 = "Bakso";
    infotypeLL itemL1_4 = "Mie Ayam";
    address P;
    CreateEmptyLinkedList(&L1);
    InsVFirstLinkedList(&L1, itemL1_1);
    InsVLastLinkedList(&L1, itemL1_2);
    InsVLastLinkedList(&L1, itemL1_3);
    InsVLastLinkedList(&L1, itemL1_4);
    Stack Histori1;
    CreateEmptyStack(&Histori1);
    OneHistory his1_1 = {"Riwayat Pembelian Pertama", 100};
    OneHistory his1_2 = {"Riwayat Pembelian Kedua", 200};
    OneHistory his1_3 = {"Riwayat Pembelian Ketiga", 300};
    PushStack(&Histori1, his1_1);
    PushStack(&Histori1, his1_2);
    PushStack(&Histori1, his1_3);
    User user1 = makeUser(1000, name1, password1, Histori1, L1);

    Word name2 = {"Athira", 6};
    Word password2 = {"67890", 5};
    LinkedList L2;
    infotypeLL itemL2_1 = "Bakwan Jagung";
    infotypeLL itemL2_2 = "Salmon Sushi";
    infotypeLL itemL2_3 = "Iga Penyet";
    infotypeLL itemL2_4 = "Bubur Ayam";
    address P;
    CreateEmptyLinkedList(&L2);
    InsVFirstLinkedList(&L2, itemL2_1);
    InsVLastLinkedList(&L2, itemL2_2);
    InsVLastLinkedList(&L2, itemL2_3);
    InsVLastLinkedList(&L2, itemL2_4);
    Stack Histori2;
    CreateEmptyStack(&Histori2);
    OneHistory his2_1 = {"Riwayat Pembelian Pertama", 200};
    OneHistory his2_2 = {"Riwayat Pembelian Kedua", 300};
    OneHistory his2_3 = {"Riwayat Pembelian Ketiga", 400};
    PushStack(&Histori2, his2_1);
    PushStack(&Histori2, his2_2);
    PushStack(&Histori2, his2_3);
    User user2 = makeUser(1500, name2, password2, Histori2, L2);

    /* Mengcek apakah user telah dibuat */
    printf("User 1: %s, %s, %d\n", user1.name, user1.password, user1.money);
    printf("User 2: %s, %s, %d\n", user2.name, user2.password, user2.money);

    /* Membuat beberapa barang */
    Word name3 = {"Buku", 4};
    Barang barang1 = makeBarang(5000, name3);

    Word name4 = {"Pensil", 6};
    Barang barang2 = makeBarang(2000, name4);

    /* Mengcek apakah barang telah dibuat */
    printf("Barang 1: %s, %d\n", barang1.name, barang1.price);
    printf("Barang 2: %s, %d\n", barang2.name, barang2.price);

    /* Mengecek apakah user1 dan user2 sama */
    printf("\nUser 1 dan User 2 sama? \n");
    if (IsSameUser(user1, user2)) {
        printf("User 1 dan User 2 sama\n");
        printf("user1 dan user2: %s\n", user1.name);
    } else {
        printf("User 1 dan User 2 berbeda\n");
        printf("user1: %s\n", user1.name);
        printf("user2: %s\n", user2.name);
    }

    /* Mengecek apakah barang1 dan barang2 sama */
    printf("\nBarang 1 dan Barang 2 sama? \n");
    if (IsSameBarang(barang1, barang2)) {
        printf("Barang 1 dan Barang 2 sama\n");
        printf("barang1 dan barang2: %s\n", barang1.name);

    } else {
        printf("Barang 1 dan Barang 2 berbeda\n");
        printf("barang1: %s\n", barang1.name);
        printf("barang2: %s\n", barang2.name);
    }

    /* Mengecek apakah string "Hello" dan "Hello" sama */
    printf("\nString 1 dan String 2 sama? \n");
    char *str1 = "Hello";
    char *str2 = "Hello";
    if (IsSameString(str1, str2)) {
        printf("String 1 dan String 2 sama\n");
        printf("String 1 dan String 2: %s\n", str1);
    } else {
        printf("String 1 dan String 2 berbeda\n");
        printf("String 1: %s\n", &str1);
        printf("String 2: %s\n", &str2);
    }

    return 0;
}