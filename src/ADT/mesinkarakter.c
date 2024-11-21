#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START(char *filename){
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    if (filename == NULL){
        pita = stdin;
    }
    else{
        pita = fopen(filename, "r");
        if (pita == NULL){
            printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
            EOP = true;
            return;
        }
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
    }
    ADV();
}

void ADV(){
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
}

char GetCC(){
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP(){
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}