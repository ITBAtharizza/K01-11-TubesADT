#include "QuantumWordl3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 4
#define MAX_ATTEMPTS 9
#define WORD_LENGTH 5

boolean isSameString(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void copyString(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void toUpperCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        i++;
    }
}

void quantumWordl3(int *score) {
    const char *wordBank[] = {
        "BUNGA", "RUMAH", "PISAU", "ANGIN", "LAMPU",
        "SAKIT", "HUJAN", "BADAI", "MERDU", "PUNYA"
    };
    int wordBankSize = sizeof(wordBank) / sizeof(wordBank[0]);
    char selectedWords[MAX_WORDS][WORD_LENGTH + 1];
    boolean guessedCorrect[MAX_WORDS] = {false};
    int attempts = 0;

    srand(time(NULL));
    for (int i = 0; i < MAX_WORDS; i++) {
        copyString(selectedWords[i], wordBank[rand() % wordBankSize]);
    }

    printf("Selamat datang di Quantum W0RDL3!\n");
    printf("Tugas Anda: Tebak 4 kata berbeda dalam 9 kesempatan.\n\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Percobaan ke-%d dari %d\n", attempts + 1, MAX_ATTEMPTS);
        printf("Masukkan 4 tebakan Anda (pisahkan dengan spasi):\n");

        char guesses[MAX_WORDS][WORD_LENGTH + 1];
        for (int i = 0; i < MAX_WORDS; i++) {
            STARTWORD(NULL);
            CopyWord();
            for (int j = 0; j < currentWord.Length; j++) {
                guesses[i][j] = currentWord.TabWord[j];
            }
            guesses[i][currentWord.Length] = '\0';
            toUpperCase(guesses[i]);
        }

        printf("\nHasil percobaan:\n");
        for (int i = 0; i < MAX_WORDS; i++) {
            if (guessedCorrect[i]) {
                printf("Kata %d sudah benar: %s\n", i + 1, selectedWords[i]);
                continue;
            }
            if (isSameString(guesses[i], selectedWords[i])) {
                guessedCorrect[i] = true;
                printf("Kata %d benar: %s\n", i + 1, guesses[i]);
            } else {
                printf("Kata %d salah: %s\n", i + 1, guesses[i]);
            }
        }

        boolean allCorrect = true;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (!guessedCorrect[i]) {
                allCorrect = false;
                break;
            }
        }

        if (allCorrect) {
            printf("\nSelamat! Anda berhasil menebak semua kata.\n");
            *score += 3000;
            return;
        }

        attempts++;
        printf("\n");
    }

    printf("Anda kehabisan kesempatan! Jawaban yang benar adalah:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("Kata %d: %s\n", i + 1, selectedWords[i]);
    }
}
