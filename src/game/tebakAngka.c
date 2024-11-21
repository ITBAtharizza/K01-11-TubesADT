#include <stdio.h>
#include <stdlib.h>
#include "tebakAngka.h"
#include "../ADT/mesinkata.h"

void tebakAngka(int* score){
    int random = rand() % 100 + 1;
    int attempt = 0;
    int chance = 10;
    printf("Hai! Aku telah memilih angka antara 1 sampai 100. Coba tebak ya!\n");
    printf("Kamu memiliki 10 kesempatan untuk menebak.\n");
    printf("Setiap kesalahan akan mengurangi kesempatan menebak dan skormu.\n");
    printf("1x percobaan benar: 500 poin\n");
    printf("2-3x percobaan benar: 300 poin\n");
    printf("4-6x percobaan benar: 100 poin\n");
    printf("7-10x percobaan benar: 50 poin\n");
    while (attempt < chance){
        printf("Masukkan tebakanmu: ");
        STARTWORD(NULL);
        int guess = 0;
        for (int i = 0; i<currentWord.Length; i++){
            guess = (guess * 10) + currentWord.TabWord[i] - '0';
        }
        attempt++;
        if (guess == random){
            printf("Selamat! Tebakanmu benar! Angka yang aku pilih adalah %d.\n", random);
            if (attempt == 1){
                *score += 500;
                printf("Kamu berhasil menebak angka tersebut dalam %d kali percobaan.\n", attempt);
            } else if (attempt <= 3){
                *score += 300;
                printf("Kamu berhasil menebak angka tersebut dalam %d kali percobaan.\n", attempt);
            } else if (attempt <= 6){
                *score += 100;
                printf("Kamu berhasil menebak angka tersebut dalam %d kali percobaan.\n", attempt);
            } else if (attempt <= 10){
                *score += 50;
                printf("Kamu berhasil menebak angka tersebut dalam %d kali percobaan.\n", attempt);
            }
            break;

        }
        else if (guess < random){
            printf("Tebakanmu terlalu kecil. Coba lagi!\n");
        }
        else if (guess > random){
            printf("Tebakanmu terlalu besar. Coba lagi!\n");
        }
        if (attempt == chance){
            printf("Kesempatanmu telah habis. Angka yang aku pilih adalah %d.\n", random);
            break;
        }
    }
    printf("kamu mendapatkan %d poin.\n", *score);
}

// int main(){
//     int score = 0;
//     tebakAngka(&score);
//     return 0;
// }