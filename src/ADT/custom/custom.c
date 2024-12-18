#include <stdio.h>
#include <stdlib.h>
#include "custom.h"

User makeMarkUser(){
    User MARK_USER;

    CopyString(MARK_USER.name, "");
    CopyString(MARK_USER.password, "");
    MARK_USER.money = -1;

    CreateEmptyMap(&MARK_USER.keranjang);

    return MARK_USER;
}

User makeUser(int money, Word name, Word password, Stack riwayat_pembelian, LinkedList wishlist){
    User user = makeMarkUser();
    CopyString(user.name,name.TabWord);
    CopyString(user.password, password.TabWord);
    user.money = money;

    user.riwayat_pembelian = riwayat_pembelian;
    user.wishlist = wishlist;

    printf("%s", user.name);
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

void CopyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

