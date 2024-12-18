#include <stdio.h>
#include <stdlib.h>
#include "custom.h"

User makeMarkUser(){
    User MARK_USER;

    CopyWord(MARK_USER.name, "");
    CopyWord(MARK_USER.password, "");
    MARK_USER.money = -1;

    CreateEmptyMap(&MARK_USER.keranjang);
    CreateEmptyStack(&MARK_USER.riwayat_pembelian);
    CreateEmptyLinkedList(&MARK_USER.wishlist);

    return MARK_USER;
}

User makeUser(int money, Word name, Word password, Stack riwayat_pembelian, LinkedList wishlist){
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

    user.riwayat_pembelian = riwayat_pembelian;
    user.wishlist = wishlist;

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
    return (user.money == -1 && user.name[0] == '\0' && user.password[0] == '\0' && IsEmptyMap(user.keranjang) && IsEmptyStack(user.riwayat_pembelian) && IsEmptyLinkedList(user.wishlist));
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