#ifndef __SAVE_H__
#define __SAVE_H__
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listdin.h"

void save(char *filename, List *list_user, ListDin *list_barang);
/*
Fungsi Save digunakan untuk menangani masukan dari pengguna untuk menyimpan state dari aplikasi ke dalam file
I.S Pengguna sudah login
F.S State dari aplikasi disimpan kedalam suatu file
*/
#endif

