#ifndef RIWAYAT_MAKSIMAL_H
#define RIWAYAT_MAKSIMAL_H

#include <stdio.h>

/**
 * @brief Menampilkan riwayat pembelian dengan total maksimal.
 *
 * @param history Array yang berisi riwayat pembelian.
 * @param count Jumlah elemen dalam riwayat.
 */
void DisplayMaxPurchase(char history[][100], int count);

/**
 * @brief Membandingkan dua string.
 * 
 * @param str1 Pointer ke string pertama.
 * @param str2 Pointer ke string kedua.
 * @return 1 jika kedua string sama, 0 jika berbeda.
 */
int IsSameString(const char *str1, const char *str2);

#endif // RIWAYAT_MAKSIMAL_H
