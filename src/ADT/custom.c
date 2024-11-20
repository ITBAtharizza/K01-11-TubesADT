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