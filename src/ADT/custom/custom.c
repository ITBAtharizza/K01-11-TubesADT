#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "custom.h"

User makeUser(int money, Word name, Word password){
    User user;
    for (int i = 0; i < name.Length; i++){
        user.name[i] = name.TabWord[i];
    }
    user.name[name.Length] = '\0';

    for (int j = 0; j < password.Length; j++){
        user.password[j] = password.TabWord[j];
    }
    user.password[password.Length] = '\0';
    user.money = money;

    return user;
}

Barang makeBarang(int price, Word name){
    Barang barang;
    for (int i = 0; i < name.Length; i++){
        barang.name[i] = name.TabWord[i];
    }
    barang.name[name.Length] = '\0';

    barang.price = price;
    return barang;
}

boolean IsMarkUser(User user){
    return (user.money == -1 && user.name[0] == '\0' && user.password[0] == '\0');
}

boolean IsSameUser(User user1, User user2){
    return (IsSameString(user1.name, user2.name) && IsSameString(user1.password, user2.password) && user1.money == user2.money);
}

boolean IsSameString(char *str1, char *str2){
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

boolean IsSameBarang(Barang barang1, Barang barang2){
    return (IsSameString(barang1.name, barang2.name) && barang1.price == barang2.price);
}