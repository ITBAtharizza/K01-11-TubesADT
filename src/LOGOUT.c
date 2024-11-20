#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.h"

// Node untuk menyimpan nama pengguna
typedef struct LogoutNode {
    Word username;               // Menggunakan tipe Word dari mesin kata
    struct LogoutNode *next;
} LogoutNode;

// Struktur utama untuk menyimpan daftar logout
typedef struct {
    LogoutNode *head;
} LogoutList;

// Inisialisasi daftar logout
void initLogoutList(LogoutList *list) {
    list->head = NULL;
}

// Menambahkan pengguna ke daftar logout
void addLogoutUser(LogoutList *list, Word username) {
    LogoutNode *newNode = (LogoutNode *)malloc(sizeof(LogoutNode));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori untuk LogoutNode.\n");
        return;
    }
    newNode->username = username; // Salin Word langsung
    newNode->next = list->head;
    list->head = newNode;
}

// Menampilkan daftar pengguna yang telah logout
void displayLogoutList(const LogoutList *list) {
    if (list->head == NULL) {
        printf("Belum ada pengguna yang logout.\n");
        return;
    }
    printf("Daftar pengguna yang telah logout:\n");
    LogoutNode *current = list->head;
    int count = 1;
    while (current != NULL) {
        // Cetak username
        printf("%d. ", count);
        for (int i = 0; i < current->username.Length; i++) {
            printf("%c", current->username.TabWord[i]);
        }
        printf("\n");
        current = current->next;
        count++;
    }
}

// Fungsi untuk logout pengguna
void logoutUser(LogoutList *list, Word username) {
    printf("Pengguna ");
    for (int i = 0; i < username.Length; i++) {
        printf("%c", username.TabWord[i]);
    }
    printf(" telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n");
    addLogoutUser(list, username); // Tambahkan ke daftar logout
}

int main() {
    LogoutList logoutList;
    initLogoutList(&logoutList);

    printf("=== Sistem Logout PURRMART ===\n");
    printf("Masukkan nama pengguna untuk logout (ketik END untuk selesai):\n");

    STARTWORD(); // Mulai membaca input menggunakan mesin kata
    while (!isEndWord()) {
        if (currentWord.Length == 3 &&
            currentWord.TabWord[0] == 'E' &&
            currentWord.TabWord[1] == 'N' &&
            currentWord.TabWord[2] == 'D') {
            break; // Keluar jika input adalah "END"
        }

        logoutUser(&logoutList, currentWord); // Proses logout pengguna
        ADVWORD(); // Lanjutkan membaca input
    }

    printf("\n=== Daftar Pengguna Logout ===\n");
    displayLogoutList(&logoutList);

    printf("Program selesai.\n");
    return 0;
}
