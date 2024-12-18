#ifndef CART_PAY_H
#define CART_PAY_H

#include "map.h"
#include <stdbool.h>

/**
 * @brief Melakukan pembayaran untuk barang-barang yang ada di keranjang.
 *
 * @param M Pointer ke Map yang merepresentasikan keranjang belanja.
 * @param userMoney Pointer ke jumlah uang pengguna.
 * @param purchaseHistory Pointer ke string untuk menyimpan riwayat pembelian.
 */
void CartPay(Map *M, int *userMoney, char *purchaseHistory);

#endif // CART_PAY_H
