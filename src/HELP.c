#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "fungsi.h"

// Fungsi untuk menampilkan daftar HELP
void displayCommandHelp(Word menuType) {
    if (IsWordEqual(menuType, "Welcome")) {
        printf("=====[ Welcome Menu Help PURRMART]=====\n");
        printf("START -> Untuk masuk sesi baru\n");
        printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } else if (IsWordEqual(menuType, "Login")) {
        printf("=====[ Login Menu Help PURRMART]=====\n");
        printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
        printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } else if (IsWordEqual(menuType, "Main")) {
        printf("=====[ Main Menu Help PURRMART]=====\n");
        printf("WORK -> Untuk bekerja\n");
        printf("WORK CHALLENGE -> Untuk mengerjakan challenge\n");
        printf("STORE LIST -> Untuk melihat barang-barang di toko\n");
        printf("STORE REQUEST -> Untuk meminta penambahan barang\n");
        printf("STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
        printf("STORE REMOVE -> Untuk menghapus barang\n");
        printf("LOGOUT -> Untuk keluar dari sesi\n");
        printf("SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } else {
        printf("Jenis menu tidak dikenali. Masukkan salah satu: Welcome, Login, Main.\n");
    }
}

// Fungsi utama
int main() {
    printf("Masukkan perintah:\n");
    STARTWORD();

    if (IsWordEqual(currentWord, "HELP")) {
        ADVWORD();
        if (!isEndWord()) {
            displayCommandHelp(currentWord);
        } else {
            printf("Masukkan jenis menu untuk bantuan (Welcome, Login, Main).\n");
        }
    } else {
        printf("Perintah tidak dikenali. Ketik 'HELP' untuk bantuan.\n");
    }

    return 0;
}
