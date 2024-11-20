#ifndef __CUSTOM_H__
#define __CUSTOM_H__

#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"

typedef struct{
  char name[50];
  char password[50];
  int money;
} User;

typedef struct{
  char name[50];
  int price;
} Barang;

User makeUser(int money, Word name, Word password);
/*Fungsi untuk membuat user
I.S Sudah tersedia uang, nama dan password untuk akun pengguna
F.S Terbentuk akun pengguna baru*/

Barang makeBarang(int price, Word name);
/*Fungsi untuk membuat barang
I.S Sudah tersedia uang dan nama untuk pengguna
F.S Terbentuk barang baru*/

#endif