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
    }
    ADV();
}

void ADV(){
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP){
        fclose(pita);
    }
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