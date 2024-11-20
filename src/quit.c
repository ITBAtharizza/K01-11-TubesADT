#include "quit.h"

void quit() {
    char pilihan;
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    scanf("%c", &pilihan);

    if (pilihan == 'Y' || pilihan == 'y') {
        // Implementasinya belum dibuat
        printf("Data sesi telah disimpan.\n");
    }
    printf("Kamu keluar dari PURRMART.\nDadah ^_^/\n");
}
