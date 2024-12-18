#ifndef CART_PAY_H
#define CART_PAY_H

#include "map.h"
#include <stdio.h>

/**
 * @brief Melakukan pembayaran untuk barang-barang yang ada di keranjang.
 *
 * @param M Pointer ke Map yang merepresentasikan keranjang belanja.
 * @param userMoney Pointer ke jumlah uang pengguna.
 * @param purchaseHistory Pointer ke string untuk menyimpan riwayat pembelian.
 */
void CartPay(Map *M, int *userMoney, char *purchaseHistory);

/**
 * @brief Membandingkan dua string.
 * 
 * @param str1 Pointer ke string pertama.
 * @param str2 Pointer ke string kedua.
 * @return 1 jika kedua string sama, 0 jika berbeda.
 */
int IsSameString(const char *str1, const char *str2);

#endif // CART_PAY_H
