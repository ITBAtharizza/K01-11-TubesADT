void MaxHistory(Stack *purchaseHistory) {
    if (IsEmpty(*purchaseHistory)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    char maxItem[150];
    int maxPrice = 0;

    Stack tempStack;
    CreateEmpty(&tempStack);

    // Proses setiap item dalam riwayat
    while (!IsEmpty(*purchaseHistory)) {
        char currentHistory[150];
        Pop(purchaseHistory, currentHistory);

        // Pisahkan nama barang dan harganya
        char itemName[100];
        int itemPrice;
        sscanf(currentHistory, "%s %d", itemName, &itemPrice);

        // Periksa apakah ini adalah harga tertinggi
        if (itemPrice > maxPrice || (itemPrice == maxPrice && strcmp(itemName, maxItem) > 0)) {
            strcpy(maxItem, itemName);
            maxPrice = itemPrice;
        }

        Push(&tempStack, currentHistory);
    }

    // Kembalikan stack ke keadaan semula
    while (!IsEmpty(tempStack)) {
        char currentHistory[150];
        Pop(&tempStack, currentHistory);
        Push(purchaseHistory, currentHistory);
    }

    // Tampilkan hasil
    printf("Barang dengan harga tertinggi yang pernah dibeli:\n");
    printf("- %s dengan harga %d\n", maxItem, maxPrice);
}
