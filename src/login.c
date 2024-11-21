#include <stdio.h>
#include "mesinkarakter.h"

#include "login.h"

void login(boolean *log_stats, List *list_user, User *logged_in) {
    char username[50];
    char password[50];
    boolean isUser = false;
    boolean isCorrectPass = false;

    printf("Username: ");
    STARTWORD(NULL);
    for (int i = 0; i < currentWord.Length; i++) {
        username[i] = currentWord.TabWord[i];
    }
    username[currentWord.Length] = '\0';

    printf("Password: ");
    ADVWORD();

    for (int i = 0; i < currentWord.Length; i++) {
        password[i] = currentWord.TabWord[i];
    }

    password[currentWord.Length] = '\0';

    int first = FirstIdx(*list_user);
    int last = LastIdx(*list_user);

    while ((first <= last) && !isCorrectPass) {
        if (IsSameString(list_user->A[first].name, username)) {
            isUser = true;
            if (IsSameString(list_user->A[first].password, password)) {
                isCorrectPass = true;
                *logged_in = list_user->A[first];
            }
        }
        first++; // Increment after the check
    }

    if (isCorrectPass && *log_stats == false) {
        printf("Anda telah login ke PURRMART sebagai %s.\n", logged_in->name);
        *log_stats = true;
    } else if (*log_stats == true) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", logged_in->name);
    } else {
        printf("Username atau password salah.\n");
    }
}
