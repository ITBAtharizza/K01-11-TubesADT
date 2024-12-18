#include "profile.h"

void profile (User *user) {
    printf("\n+----------------------------------------+\n");
    printf("|             Profil Pengguna            |\n");
    printf("+----------------------------------------+\n");
    printf("| Nama  : %-30s |\n", user->name);
    printf("| Saldo : %-30d |\n", user->money);
    printf("+----------------------------------------+\n");
}