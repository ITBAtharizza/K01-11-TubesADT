#ifndef CART_REMOVE_H
#define CART_REMOVE_H

#include "map.h"
#include <stdbool.h>

/**
 * @brief Menghapus barang dari keranjang belanja.
 *
 * @param M Pointer ke Map yang merepresentasikan keranjang belanja.
 * @param k Key barang yang akan dihapus.
 * @param n Jumlah barang yang akan dihapus.
 */
void CartRemove(Map *M, keytype k, valuetype n);

#endif // CART_REMOVE_H
