#include <stdio.h>
#include "list.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"

// fungsi untuk membandingkan dua string
boolean TwoString(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

// fungsi untuk salin string secara manual
void CopyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void Register(List *list_user) {
    char username[50];
    char password[50];
    boolean usernameExists = false;

    // input Username
    printf("Username: ");
    STARTWORD(NULL);
    for (int i = 0; i < currentWord.Length; i++) {
        username[i] = currentWord.TabWord[i];
    }
    username[currentWord.Length] = '\0';

    // cek apakah username sudah ada
    for (int i = FirstIdx(*list_user); i <= LastIdx(*list_user); i++) {
        if (IsSameString(list_user->A[i].name, username)) {
            usernameExists = true;
            break;
        }
    }

    if (usernameExists) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return;
    }

    // input Password
    printf("Password: ");
    ADVWORD();
    for (int i = 0; i < currentWord.Length; i++) {
        password[i] = currentWord.TabWord[i];
    }
    password[currentWord.Length] = '\0';

    // tambahkan pengguna baru
    User newUser;
    CopyString(newUser.name, username);
    CopyString(newUser.password, password);
    newUser.money = 0;

    InsertLast(list_user, newUser);
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}