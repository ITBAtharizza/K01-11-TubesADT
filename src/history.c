#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"


void History(Stack *purchaseHistory, int n) {
    if (IsEmpty(*purchaseHistory)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");
    Stack tempStack;
    CreateEmpty(&tempStack);

    int count = 0;
    while (!IsEmpty(*purchaseHistory) && count < n) {
        char topHistory[150];
        Pop(purchaseHistory, topHistory);
        printf("%d. %s\n", count + 1, topHistory);
        Push(&tempStack, topHistory);
        count++;
    }

    // Restore the original stack
    while (!IsEmpty(tempStack)) {
        char topHistory[150];
        Pop(&tempStack, topHistory);
        Push(purchaseHistory, topHistory);
    }
} 
