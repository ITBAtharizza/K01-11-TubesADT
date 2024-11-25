#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "wordl3.h"

void wordl3(int *score)
{
    printf("\n");
    printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n");

    // jawaban
    char *word[JUMLAH_KATA] = {
    "BUNGA", "RUMAH", "PISAU", "ANGIN", "LAMPU", 
    "SAKIT", "HUJAN", "BADAI", "MERDU", "PUNYA",
    "SIHIR", "MINTA", "BARAT", "TIMUR", "RUMIT", 
    "BAWAH", "CINTA", "TANAH", "SEGAR", "GARIS",
    "BULAN", "BADAK", "BUAYA", "BERAS", "ZEBRA",
    "ASING", "LUMUT", "KANAN", "KOMIK", "EMANG", 
    };

    // kata yang dipilih secara acak
    srand(time(NULL));
    int idx = rand() % 52;
    // printf("%d\n", idx); buat liat idx
    char *KJ = word[idx];

    // permainan
    int prize = 1500;

    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("\n");

    boolean correct = false;

    char arrCorrect[5][5] =  {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    char arrJwbn[5][5] = 
    {
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'}
    };


    // Buat while loop & gunakan counter chance
    int chance = 0;
    while (chance < 5)
    {
        printf("Masukan kata tebakan Anda: ");
        STARTWORD(NULL);
        char jwbn[5];
        CopyString(jwbn, currentWord.TabWord);
        CopyString(arrJwbn[chance], jwbn);
    
        for (int i = 0; i < 5; i++)
        {
            if (jwbn[i] == KJ[i])
            {
                correct = true;
            }
            else
            {
                correct = false;
            }
        }
        
        if (correct)
        {
            break; // break jika jwbn benar dan akan ditampilkan
        }
        
        for (int i = 0; i < 5; i++)
        {
            // nilai kebenaran dimasukkan ke dalam arrCorrect
            // % = salah, * = benar
            if (jwbn[i] == KJ[0] || jwbn[i] == KJ[1] || jwbn[i] == KJ[2] || jwbn[i] == KJ[3] || jwbn[i] == KJ[4])
            {
                arrCorrect[chance][i] = '*';
            } 
            else
            {
                arrCorrect[chance][i] = '%';
            }
        }
        // di akhir ditulis seperti ini A% D% I% E% U*
    
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c", arrJwbn[i][j]);
                if (arrCorrect[i][j] != ' ')
                {
                    printf("%c", arrCorrect[i][j]);
                }
                printf(" ");
            }
            printf("\n");
        }
        chance++;
        printf("\n");
    }
    
    // kalo jawaban benar sebelum percobaan habis, tetap ditulis
    // jawaban-kebenaran-spasi

    if (chance < 5)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c", arrJwbn[i][j]);
                if (arrCorrect[i][j] != ' ')
                {
                    printf("%c", arrCorrect[i][j]);
                }
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // hasil game
    if (correct)
    {
        printf("Selamat, Anda menang!\n\n");
        printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
        *score += prize;
    }
    else
    {
        printf("Boo! Anda kalah. Jawabannya adalah %s\n\n", KJ);
    }

}

// int main() {
//     int score = 10000; // Saldo awal
//     printf("Saldo awal Anda: %d\n", score);

//     wordl3(&score); // Memanggil fungsi dengan pointer

//     printf("Saldo akhir Anda: %d\n", score);
//     return 0;
// }
