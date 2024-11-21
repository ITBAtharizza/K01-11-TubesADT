#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

void STARTGAME() {
    // Use forward slashes for Mac paths
    char *fname = "../save/here.txt";
    
    // Add file existence check
    FILE *f = fopen(fname, "r");
    if (f == NULL) {
        printf("Error: Configuration file not found\n");
        return;
    }
    fclose(f);

    // Start word reading with error check
    STARTWORD(fname);
    if (currentWord.Length == 0) {
        printf("Error: Empty configuration file\n");
        return;
    }

    // Safe conversion of first character to integer
   
    int loop = currentWord.TabWord[0] - '0';

    // Add bounds check for loop
    if (loop < 0 || loop > 9) {
        printf("Error: Invalid loop count range\n");
        return;
    }

    printf("Starting game with %d iterations\n", loop);
    
    // Safe loop with counter
    int count = 0;
    for (int count = 0; count < loop && !isEndWord(); count++) {
        ADVWORD();
        if (!isEndWord()) {
            printf("Read word: %.*s\n", currentWord.Length, currentWord.TabWord);
        }
    }
}