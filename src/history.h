#ifndef HISTORY_H
#define HISTORY_H

#include <stdbool.h>

/**
 * @brief Menambahkan riwayat pembelian ke daftar riwayat.
 *
 * @param purchaseHistory String yang merepresentasikan pembelian yang akan disimpan ke riwayat.
 * @param history Array untuk menyimpan riwayat pembelian.
 * @param count Pointer ke jumlah elemen dalam riwayat.
 */
void AddToHistory(char *purchaseHistory, char history[][100], int *count);

/**
 * @brief Menampilkan semua riwayat pembelian.
 *
 * @param history Array yang berisi riwayat pembelian.
 * @param count Jumlah elemen dalam riwayat.
 */
void DisplayHistory(char history[][100], int count);

#endif // HISTORY_H
