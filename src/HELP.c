#include <stdio.h>
#include <string.h>
#include "command.h"

void parseCommand(Word input, Command *cmd) {
    /* Memisahkan kata dari input dan menyimpannya dalam struktur Command */
    cmd->word_count = 0;
    int i = 0, startIdx = 0;

    while (i <= input.Length) {
        if (i == input.Length || input.TabWord[i] == BLANK) {
            // Kata selesai (atau akhir input)
            if (startIdx < i) {
                int length = i - startIdx;
                strncpy(cmd->words[cmd->word_count].TabWord, &input.TabWord[startIdx], length);
                cmd->words[cmd->word_count].TabWord[length] = '\0'; // Null-terminate
                cmd->words[cmd->word_count].Length = length;
                cmd->word_count++;
            }
            startIdx = i + 1; // Update indeks awal kata berikutnya
        }
        i++;
    }
}

void displayCommandHelp(const char *menuType) {
    /* Menampilkan daftar command sesuai dengan menuType */
    if (strcmp(menuType, "Welcome") == 0) {
        printf("=====[ Welcome Menu Help PURRMART ]=====\n");
        printf("START -> Untuk masuk sesi baru\n");
        printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } else if (strcmp(menuType, "Login") == 0) {
        printf("=====[ Login Menu Help PURRMART ]=====\n");
        printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
        printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } else if (strcmp(menuType, "Main") == 0) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("WORK -> Untuk bekerja\n");
        printf("WORK CHALLENGE -> Untuk mengerjakan challenge\n");
        printf("STORE LIST -> Untuk melihat barang-barang di toko\n");
        printf("STORE REQUEST -> Untuk meminta penambahan barang\n");
        printf("STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
        printf("STORE REMOVE -> Untuk menghapus barang\n");
        printf("LOGOUT -> Untuk keluar dari sesi\n");
        printf("SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("QUIT -> Untuk keluar dari program\n");
    }
}
