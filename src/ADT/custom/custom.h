#ifndef __CUSTOM_H__
#define __CUSTOM_H__

#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../mesinkata/mesinkata.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"
#include "../map/map.h"

typedef struct{
  char name[50];
  char password[50];
  int money;
  Map keranjang;
  Stack riwayat_pembelian;
  LinkedList wishlist;
} User;

typedef struct {
	Barang Barang;
	int Quantity;
} Pembelian;

typedef struct {
  char name[50];
  int income;
  int duration; //durasi dalam detik
} Job;


User makeMarkUser();

User makeUser(int money, Word name, Word password, Stack riwayat_pembelian, LinkedList wishlist);
/*Fungsi untuk membuat user
I.S Sudah tersedia uang, nama dan password untuk akun pengguna
F.S Terbentuk akun pengguna baru*/

Barang makeBarang(int price, Word name);
/*Fungsi untuk membuat barang
I.S Sudah tersedia uang dan nama untuk pengguna
F.S Terbentuk barang baru*/

boolean IsMarkUser(User user);
/*Fungsi untuk mengecek apakah list user sudah mencapai ujung yang ditandai dengan MARK_USER
I.S Sudah tersedia list
*/

boolean IsSameUser(User user1, User user2);
/*Fungsi untuk mengecek apakah user yang dicari sama dengan user yang dibaca saat search
I.S. Diterima masukan data user1 dan user2 yang akan dibandingkan.
*/

boolean IsSameBarang(Barang barang1, Barang barang2);
/*Fungsi mengecek apakah user yang dicari sama dengan barang yang dibaca saat search
I.S Diterima masukan data barang1 dan barang2 yang akan dibandingkan.
*/

boolean IsSameString(char *str1, char *str2);
/*Fungsi mengecek apakah string yang dimasukan sama dengan string yang dibaca
I.S Diterima masukan data string1 dan string2 yang akan dibandingkan.
*/

void CopyString(char *dest, char *src);
#endif