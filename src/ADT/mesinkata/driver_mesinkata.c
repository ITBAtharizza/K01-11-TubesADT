#include <stdio.h>
#include "mesinkata.h"

int main() {
   /* Membuat dummy file yang akan dibaca menggunakan mesin karaktrer */
    char filename[] = "file.txt";
    
    /* Mulai membaca isi dari file.txt */
    STARTWORD(filename);
    printf("Kata-kata dalam file:\n");

    /* Melakukan pembacaan kata */
    while (!isEndWord()) {
        printf("Kata: ");
        // Print Kata
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        // Print Panjang Kata
        printf(" (Panjang: %d)\n", currentWord.Length);

        /* Melanjutkan pembacaan kata selanjutnya hingga mencapai endWord */
        ADVWORD();
    }

    /* Kondisi ketika pita karakter sudah mencapai endWord */
    printf("\nSelesai membaca semua kata.\n");
    return 0;
}
