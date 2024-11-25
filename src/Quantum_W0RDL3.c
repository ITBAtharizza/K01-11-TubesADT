#include "quantum_wordl3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 4
#define MAX_ATTEMPTS 9
#define WORD_LENGTH 5

void quantumWordl3(int *score) {

    const char *wordBank[] = {
        "BUNGA", "RUMAH", "PISAU", "ANGIN", "LAMPU",
        "SAKIT", "HUJAN", "BADAI", "MERDU", "PUNYA"
    };
    int wordBankSize = sizeof(wordBank) / sizeof(wordBank[0]);


    char selectedWords[MAX_WORDS][WORD_LENGTH + 1];
    srand(time(NULL));
    for (int i = 0; i < MAX_WORDS; i++) {
        strcpy(selectedWords[i], wordBank[rand() % wordBankSize]);
    }

    printf("Selamat datang di Quantum W0RDL3!\n");
    printf("Tugas Anda: Tebak 4 kata berbeda dalam 9 kesempatan.\n\n");

    char guesses[MAX_WORDS][WORD_LENGTH + 1];
    boolean guessedCorrect[MAX_WORDS] = {false};
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Percobaan ke-%d dari %d\n", attempts + 1, MAX_ATTEMPTS);
        printf("Masukkan 4 tebakan Anda (pisahkan dengan spasi):\n");

   
        for (int i = 0; i < MAX_WORDS; i++) {
            STARTWORD(NULL); 
            CopyWord();
            strncpy(guesses[i], currentWord.TabWord, currentWord.Length);
            guesses[i][currentWord.Length] = '\0';
            for (int j = 0; j < WORD_LENGTH; j++) {
                guesses[i][j] = toupper(guesses[i][j]);
            }
        }

    
        printf("\nHasil percobaan:\n");
        for (int i = 0; i < MAX_WORDS; i++) {
            if (guessedCorrect[i]) {
                printf("Kata %d sudah benar: %s\n", i + 1, selectedWords[i]);
                continue;
            }

            if (strcmp(guesses[i], selectedWords[i]) == 0) {
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
