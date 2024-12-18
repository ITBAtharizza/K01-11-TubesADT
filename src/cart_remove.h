#ifndef CART_REMOVE_H
#define CART_REMOVE_H

#include "map.h"
#include <stdio.h>

/**
 * @brief Menghapus barang dari keranjang belanja.
 *
 * @param M Pointer ke Map yang merepresentasikan keranjang belanja.
 * @param k Key barang yang akan dihapus.
 * @param n Jumlah barang yang akan dihapus.
 */
void CartRemove(Map *M, keytype k, valuetype n);

/**
 * @brief Membandingkan dua string.
 * 
 * @param str1 Pointer ke string pertama.
 * @param str2 Pointer ke string kedua.
 * @return 1 jika kedua string sama, 0 jika berbeda.
 */
int IsSameString(const char *str1, const char *str2);

#endif // CART_REMOVE_H
