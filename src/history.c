void AddToHistory(char *history[], int *historyCount, char *item, int quantity) {
    if (*historyCount < MAX_HISTORY) {
        for (int i = 0; i < *historyCount; i++) {
            if (IsSameString(history[i], item)) {
                printf("Item sudah tercatat di history.\n");
                return;
            }
        }
        history[*historyCount] = item;
        (*historyCount)++;
        printf("Item %s dengan jumlah %d berhasil ditambahkan ke history.\n", item, quantity);
    } else {
        printf("History penuh, tidak bisa menambahkan lebih banyak data.\n");
    }
}
