#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"

void CartPay(Map *M, int *userMoney, char *purchaseHistory) {
    if (IsEmptyMap(*M)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    int totalCost = 0;
    char highestPricedItem[100] = "";
    int highestPrice = 0;

    printf("Kamu akan membeli barang-barang berikut.\n");
    printf("Kuantitas  Nama    Total\n");

    for (int i = 0; i < M->Count; i++) {
        int itemCost = M->Elements[i].Value;
        printf("%d          %d      %d\n", M->Elements[i].Value, M->Elements[i].Key, itemCost);
        totalCost += itemCost;

        if (itemCost > highestPrice || (itemCost == highestPrice && strcmp(M->Elements[i].Key, highestPricedItem) > 0)) {
            strcpy(highestPricedItem, M->Elements[i].Key);
            highestPrice = itemCost;
        }
    }

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalCost);

    char response[10];
    scanf("%s", response);

    if (strcmp(response, "Ya") == 0) {
        if (*userMoney >= totalCost) {
            *userMoney -= totalCost;
            sprintf(purchaseHistory, "Barang: %s, Total: %d", highestPricedItem, highestPrice);
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            CreateEmptyMap(M);
        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", *userMoney);
        }
    } else if (strcmp(response, "Tidak") == 0) {
        printf("Pembelian dibatalkan.\n");
    } else {
        printf("Input tidak valid. Kembali ke menu utama.\n");
    }
}
