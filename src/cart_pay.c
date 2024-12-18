#include "cart_pay.h"

void CartPay(Map *M, int *userMoney, char *purchaseHistory) {
    if (IsEmptyMap(*M)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    int totalCost = 0;
    char highestPricedItem[100] = "";
    int highestPrice = 0;

    printf("Kamu akan membeli barang-barang berikut:\n");
    printf("Kuantitas  Nama         Total\n");

    for (int i = 0; i < M->Count; i++) {
        int itemCost = M->Elements[i].Value;
        printf("%d          %s      %d\n", M->Elements[i].Value, M->Elements[i].Key, itemCost);
        totalCost += itemCost;

        // Cari barang dengan harga tertinggi
        if (itemCost > highestPrice || 
           (itemCost == highestPrice && !IsSameString(highestPricedItem, M->Elements[i].Key) && M->Elements[i].Key[0] > highestPricedItem[0])) {
            int j = 0;
            while (M->Elements[i].Key[j] != '\0') {
                highestPricedItem[j] = M->Elements[i].Key[j];
                j++;
            }
            highestPricedItem[j] = '\0'; // Tambahkan null terminator
            highestPrice = itemCost;
        }
    }

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalCost);

    char response[10];
    scanf("%s", response);

    if (IsSameString(response, "Ya")) {
        if (*userMoney >= totalCost) {
            *userMoney -= totalCost;
            sprintf(purchaseHistory, "Barang: %s, Total: %d", highestPricedItem, highestPrice);
            printf("Selamat, kamu telah membeli barang-barang tersebut!\n");
            CreateEmptyMap(M);
        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", *userMoney);
        }
    } else if (IsSameString(response, "Tidak")) {
        printf("Pembelian dibatalkan.\n");
    } else {
        printf("Input tidak valid. Kembali ke menu utama.\n");
    }
}
