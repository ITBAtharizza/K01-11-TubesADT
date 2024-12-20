#include <stdio.h>
#include "stack.h"

int main() {
    Stack myStack;
    OneHistory temp;

    // Inisialisasi stack
    CreateEmptyStack(&myStack);

    // Menambahkan elemen ke stack
    OneHistory h1 = {"Riwayat Pembelian Pertama", 100};
    OneHistory h2 = {"Riwayat Pembelian Kedua", 200};
    OneHistory h3 = {"Riwayat Pembelian Ketiga", 300};

    printf("Push elemen ke stack...\n");
    PushStack(&myStack, h1);
    PushStack(&myStack, h2);
    PushStack(&myStack, h3);

    // Menampilkan isi stack
    printf("\nIsi stack:\n");
    for (int i = 0; i <= Top(myStack); i++) {
        PrintOneHistory(myStack.T[i]);
    }

    // Pop elemen dari stack
    printf("\nPop elemen dari stack...\n");
    PopStack(&myStack, &temp);
    printf("Elemen yang di-pop: ");
    PrintOneHistory(temp);

    // Menampilkan isi stack setelah pop
    printf("\nIsi stack setelah pop:\n");
    for (int i = 0; i <= Top(myStack); i++) {
        PrintOneHistory(myStack.T[i]);
    }

    // Membalik stack
    printf("\nMembalik isi stack...\n");
    FlipStack(&myStack);

    // Menampilkan isi stack setelah dibalik
    printf("\nIsi stack setelah dibalik:\n");
    for (int i = 0; i <= Top(myStack); i++) {
        PrintOneHistory(myStack.T[i]);
    }

    return 0;
}
