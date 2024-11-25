#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    /* Membuat dummy file yang akan dibaca menggunakan mesin karaktrer */
    char filename[] = "file.txt";
    
    /* Mulai membaca isi dari file.txt */
    START(filename);

    if (!IsEOP()) {
        printf("Mulai membaca isi file pita karakter\n");
    }

    /* Program akan menampilkan karakter demi karakter isi dari file.txt */
    while (!IsEOP()) {
        printf("Karakter yang dibaca: %c\n", GetCC());
        ADV();
    }

    /* Program sudah mendeteksi EOP dan sudah mencapai akhir dari pita karakter */
    printf("Program sudah mencapai akhir dari pita karakter\n");

    return 0;
}
