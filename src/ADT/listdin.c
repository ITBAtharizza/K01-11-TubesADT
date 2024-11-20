#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListDin kosong dengan ukuran InitialSize
 */
ListDin MakeListDin(){
    ListDin array;
    array.A = (ElTypeBarang *) malloc(InitialSize * sizeof(ElTypeBarang));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateListDin(ListDin *array){
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyListDin(ListDin array){
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthListDin(ListDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeBarang GetListDin(ListDin array, IdxType i){
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityListDin(ListDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 * Jika array penuh, maka array akan diperbesar sebanyak InitialSize.
 */
void InsertAtListDin(ListDin *array, ElTypeBarang el, IdxType i){
    int length = LengthListDin(*array);
    int capacity = GetCapacityListDin(*array);

    if (length == capacity){
        int desiredCapacity = capacity + InitialSize;
        ElTypeBarang *arr = (ElTypeBarang *) malloc(desiredCapacity * sizeof(ElTypeBarang));
        for (int a = 0; a < length; a++){
            arr[a] = GetListDin(*array, a);
        }
        free(array->A);
        
        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--){
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastListDin(ListDin *array, ElTypeBarang el){
    int insertAt = LengthListDin(*array);
    InsertAtListDin(array, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstListDin(ListDin *array, ElTypeBarang el){
    InsertAtListDin(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtListDin(ListDin *array, IdxType i){
    int length = LengthListDin(*array);
    for (int a = i; a < length - 1; a++){
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ListDin
 * Prekondisi: array tidak kosong
 */
void DeleteLastListDin(ListDin *array){
    int deleteAt = LengthListDin(*array) - 1;
    DeleteAtListDin(array, deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ListDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirstListDin(ListDin *array){
    DeleteAtListDin(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ListDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintListDin(ListDin array){
    if (IsEmptyListDin(array)){
        printf("[]\n");
    } else{
        printf("[");
        for (int i = 0; i < array.Neff; i++){
            printf("%d", array.A[i]);
            if (i < array.Neff - 1){
                printf(", ");
            }
        }
        printf("]\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ListDin.
 * Prekondisi: array terdefinisi
 */
void ReverseListDin(ListDin *array){
    int length = LengthListDin(*array);
    for (int i = 0; i < length / 2; i++){
        ElTypeBarang temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ListDin.
 * Prekondisi: array terdefinisi
 */
ListDin CopyListDin(ListDin array){
    ListDin copy = MakeListDin();
    for (int i = 0; i < array.Neff; i++){
        InsertLastListDin(&copy, array.A[i]);
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ListDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchListDin(ListDin array, ElTypeBarang el){
    for (int i = 0; i < array.Neff; i++){
        if (IsSameBarang(array.A[i], el)){
            return i;
        }
    }
    return -1;
}