#include <stdio.h>
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)==NilStack);
}

boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S)==MaxElStack-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack (Stack * S, OneHistory X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack (Stack * S, OneHistory* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

void FlipStack(Stack *S) {
    Stack temp;
    OneHistory X;        

    CreateEmptyStack(&temp);

    while (!IsEmptyStack(*S)) {
        PopStack(S, &X);
        PushStack(&temp, X);
    }
    *S = temp;
}