#include <stdio.h>
#include "ADT/boolean.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/list.h"
#include "ADT/listdin.h"
#include "ADT/queue.h"
#include "ADT/custom.h"
#include "console.h"

//start
//fungsi start

//load
void Load(char *filename, List *list_user, ListDin *list_barang){
    STARTWORD(filename);
    
    if (IsEOP()){
        return;
    }

    int jumlah_barang = WordToInt(currentWord);

    for (int i = 0; i < jumlah_barang; i++){
        ADVWORD();
        int price = WordToInt(currentWord);
        Word name;
        name.Length = 0;
        
        char goods[50] = "";
        int length = 0;

        while (true){
            ADVWORD();
            GoodsWithManyWords(goods, &length, currentWord);

            if (isEndWord()){
                break;
            }
        }

        if (length > 0 && goods[length - 1] == ' '){
            goods[length - 1] = '\0';
            length -= 1;
        }

        if (length > 50){
            length = 50;
        }

        for (int j = 0; j < length && j < 50; j++){
            name.TabWord[j] = goods[j];
        }            
        name.TabWord[length] = '\0';
        name.Length = length;

        Barang barang = makeBarang(price, name);
        InsertLastListDin(list_barang, barang);
    }

    ADVWORD();
    int jumlah_user = WordToInt(currentWord);

    for (int i = 0; i < jumlah_user; i++){
        ADVWORD();
        int money = WordToInt(currentWord);

        ADVWORD();
        Word name = currentWord;
        
        ADVWORD();
        Word password = currentWord;

        User user = makeUser(money, name, password);

        InsertLast(list_user, user);
    }
}

//register
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

//login
void Login(List *list_user, User *logged_in, boolean *log_stats) {
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
        printf("Anda telah login ke PURRMART sebagai %s.\n\n", logged_in->name);
        *log_stats = true;
    } else if (*log_stats == true) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n\n", logged_in->name);
    } else {
        printf("Username atau password salah.\n\n");
    }
}
//work
//fungsi work

//work challenge
//fungsi work challenge

//store list
void StoreList(ListDin list_barang){
    PrintListDin(list_barang);
}

//store request
void Request(Queue *antrian, ListDin *list_barang){
    printf("Nama barang yang diminta: ");
    STARTWORD(NULL);

    Word name;
    name.Length = 0;

    char goods[50] = "";
    int length = 0;

    GoodsWithManyWords(goods, &length, currentWord);
    while (!isEndWord()){
        ADVWORD();
        GoodsWithManyWords(goods, &length, currentWord);
    }

    if (length > 0 && goods[length - 1] == ' '){
        goods[length - 1] = '\0';
        length -= 1;
    }

    if (length > 50){
        length = 50;
    }

    for (int j = 0; j < length && j < 50; j++){
        name.TabWord[j] = goods[j];
    }
    name.TabWord[length] = '\0';
    name.Length = length;

    if (!IsMemberListDin(*list_barang, name)){
        if (!isMemberQueue(*antrian, name)){
            enqueue(antrian, name);
        }
    }
}

//store supply
void Supply(Queue *antrian, ListDin *list_barang){
    Word val;
    dequeue(antrian, &val);
    printf("Apakah kamu ingin menambahkan barang %s: ", val.TabWord);
    STARTWORD(NULL);
    if (IsWordEqual(currentWord, "Terima")){
        printf("Harga barang: ");
        ADVWORD();
        int Harga = WordToInt(currentWord);
        if (Harga != -9999){
            Barang barang = makeBarang(Harga, val);
            InsertLastListDin(list_barang, barang);
            printf("\"%s\" dengan harga %d telah ditambahkan ke toko.\n", list_barang->A[list_barang->Neff-1].name, list_barang->A[list_barang->Neff-1].price);
        }
    }
    else if (IsWordEqual(currentWord, "Tunda")){
        enqueue(antrian, val);
        printf("\"%s\" dikembalikan ke antrian.\n", val);
    }
    else if (IsWordEqual(currentWord, "Tolak")){
        printf("\"%s\" dihapuskan dari antrian.\n", val);
    }
}

//store remove
//fungsi store remove

//logout
//fungsi logout

//save
//fungsi save

//quit
//fungsi quit

//help
void Help(int where) {
    if (where == 0) {
        printf("====================[ Welcome Menu Help PURRMART ]====================\n");
        printf("  START          -> Untuk masuk sesi baru\n");
        printf("  LOAD           -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("  QUIT           -> Untuk keluar dari program\n\n");
    } else if (where == 1) {
        printf("====================[ Login Menu Help PURRMART ]====================\n");
        printf("  REGISTER       -> Untuk melakukan pendaftaran akun baru\n");
        printf("  LOGIN          -> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("  QUIT           -> Untuk keluar dari program\n\n");
    } else if (where == 2) {
        printf("====================[ Main Menu Help PURRMART ]====================\n");
        printf("  WORK           -> Untuk bekerja\n");
        printf("  WORK CHALLENGE -> Untuk mengerjakan challenge\n");
        printf("  STORE LIST     -> Untuk melihat barang-barang di toko\n");
        printf("  STORE REQUEST  -> Untuk meminta penambahan barang\n");
        printf("  STORE SUPPLY   -> Untuk menambahkan barang dari permintaan\n");
        printf("  STORE REMOVE   -> Untuk menghapus barang\n");
        printf("  LOGOUT         -> Untuk keluar dari sesi\n");
        printf("  SAVE           -> Untuk menyimpan state ke dalam file\n");
        printf("  QUIT           -> Untuk keluar dari program\n\n");
    }
}

//fungsi-fungsi pembantu
//fungsi IsWordEqual
boolean IsWordEqual(Word word, char *reference){
    int length = 0;
    while (reference[length] != '\0'){
        length++;
    }

    if (word.Length != length){
        return false;
    }

    for (int i = 0; i < word.Length; i++){
        if (word.TabWord[i] != reference[i]){
            return false;
        }
    }

    return true;
}

//fungsi WordToInt
int WordToInt(Word word){
    int integer = 0;
    for (int i = 0; i < word.Length; i++){
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9'){
            printf("Bukan Angka Valid!\n");
            return -9999;
        }
        else{
            integer *= 10;
            integer += word.TabWord[i] - '0';
        }
    }
    return integer;
}

//fungsi GoodsWithManyWords
void GoodsWithManyWords(char *goods, int *length, Word currentWord){
    if (*length >= 50){
        return;
    }

    int spaceLeft = 50 - *length;
    int charactersToAdd = (currentWord.Length < spaceLeft) ? currentWord.Length : spaceLeft;

    for (int i = 0; i < charactersToAdd; i++){
        goods[*length + i] = currentWord.TabWord[i];
    }
    *length += charactersToAdd;

    if (*length < 50){
        goods[*length] = ' ';
        *length += 1;
    }
    else{
        goods[*length] = '\0';
    }

    goods[*length] = '\0';
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

// fungsi untuk salin string secara manual
void CopyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void DisplayUser(List list_user) {
    if (IsEmpty(list_user)) {
        printf("No users available.\n");
    } else {
        printf("========================================================================================================================\n");
        printf("| %-50s | %-50s | %-10s |\n", "Username", "Password", "Money");
        printf("========================================================================================================================\n");

        for (IdxType i = FirstIdx(list_user); i <= LastIdx(list_user); i++) {
            printf("| %-50s | %-50s | %-10d |\n", list_user.A[i].name, list_user.A[i].password, list_user.A[i].money);
        }

        printf("========================================================================================================================\n\n");
    }
}



