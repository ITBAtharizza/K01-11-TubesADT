#ifndef __LISTDIN_H__
#define __LISTDIN_H__

#include "../../boolean.h"
#include "../custom/custom.h"

#define InitialSize 10

typedef int IdxType;
typedef Barang ElTypeBarang;
typedef struct{
    ElTypeBarang *A;
    int Capacity;
    int Neff;
} ListDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListDin kosong dengan ukuran InitialSize
 */
ListDin MakeListDin();

/**
 * Destruktor
 * I.S. ListDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateListDin(ListDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyListDin(ListDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthListDin(ListDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeBarang GetListDin(ListDin array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityListDin(ListDin array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtListDin(ListDin *array, ElTypeBarang el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastListDin(ListDin *array, ElTypeBarang el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstListDin(ListDin *array, ElTypeBarang el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ListDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtListDin(ListDin *array, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir ListDin
 * Prekondisi: array tidak kosong
 */
void DeleteLastListDin(ListDin *array);

/**
 * Fungsi untuk menghapus elemen pertama ListDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirstListDin(ListDin *array);

/**
 * Fungsi untuk melakukan print suatu ListDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintListDin(ListDin array);

/**
 * Fungsi untuk melakukan reverse suatu ListDin.
 * Prekondisi: array terdefinisi
 */
void ReverseListDin(ListDin *array);

/**
 * Fungsi untuk melakukan copy suatu ListDin.
 * Prekondisi: array terdefinisi
 */
ListDin CopyListDin(ListDin array);

/**
 * Fungsi untuk melakukan search suatu ListDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchListDin(ListDin array, ElTypeBarang el);

boolean IsMemberListDin(ListDin array, Word word);

#endif