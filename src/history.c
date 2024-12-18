#include "history.h"

void AddToHistory(Stack *history, infotype purchase) {
    PushStack(history, purchase);
}

void ShowHistory(Stack *history) {
    if (IsEmptyStack(*history)) {
        printf("Tidak ada riwayat pembelian.\n");
    } else {
        // belum kepikiran
}
}