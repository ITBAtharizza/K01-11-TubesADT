#include <stdio.h>
#include "login.h"

void login(boolean *log_stats, List *list_user, User *logged_in) {
    char username[50];
    char password[50];
    boolean isUser = false;
    boolean isCorrectPass = false;
    printf("Username: ");
    STARTWORD(NULL);
    for (int i = 0; i < currentWord.Length; i++){
            username[i] = currentWord.TabWord[i];
        }
        username[currentWord.Length] = '\0';
    printf("Password: ");
    ADVWORD();
    for (int i = 0; i < currentWord.Length; i++){
            username[i] = currentWord.TabWord[i];
        }
        username[currentWord.Length] = '\0';
    int first = FirstIdx(*list_user);
	int last = LastIdx(*list_user);
	while ((first <= last) && !isUser){
		first++;
		if (IsSameString(list_user->A[first].name, username)){
			isUser = true;
            if (IsSameString(list_user->A[first].password, password)){
                isCorrectPass = true;
                *logged_in = list_user->A[first];
            }
		}
	}
    if (isCorrectPass){
        printf("Anda telah login ke PURRMART sebagai %s.\n", list_user->A[first].name);
        log_stats = true;
    } else if (log_stats == true) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", logged_in->name);
    } else {
        printf("Username atau password salah.\n");
    }
}