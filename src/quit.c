#include "quit.h"
#include "save.h"

void quit(List *list_user, ListDin *list_barang) {
    char pilihan;
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    scanf("%c", &pilihan);

    if (pilihan == 'Y' || pilihan == 'y') {
        char filename[55];
        printf("Masukkan nama file: ");
        scanf("%s", filename);

        save(filename, list_user, list_barang);
        printf("Data sesi telah disimpan ke %s.\n", filename);
    }
    printf("Kamu keluar dari PURRMART.\nDadah ^_^/\n");
}
