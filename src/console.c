#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

//start
void Start(List *list_user, ListDin *list_barang, int *where){
    Load("default.txt", list_user, list_barang, where);
}

//load
void Load(char *filename, List *list_user, ListDin *list_barang, int *where){
    char path[100] = "../save/";
    int idx = 0;
    while (filename[idx] != '\0' && idx < 50) {
        path[8 + idx] = filename[idx];
        idx++;
    }
    path[8 + idx] = '\0';

    STARTWORD(path);
    
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
    *where = 1;
}

//register
void Register(List *list_user) {
    char username[50];
    char password[50];
    boolean usernameExists = false;

    printf("Username: ");
    STARTWORD(NULL);
    CopyString(username, currentWord.TabWord);

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

    printf("Password: ");
    STARTWORD(NULL);
    CopyString(password, currentWord.TabWord);

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
    CopyString(username, currentWord.TabWord);

    printf("Password: ");
    STARTWORD(NULL);
    CopyString(password, currentWord.TabWord);

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
        first++;
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
void WorkChallenge(User *logged_in){
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n\n");
    printf("Masukan challenge yang hendak dimainkan: ");
    STARTWORD(NULL);
    int gamescore = 0;
    int gamechoice = WordToInt(currentWord);
    if (gamechoice != 1 && gamechoice != 2){
        printf("Angka tidak valid! Kembali ke menu utama...\n");
    }
    else{
        if (gamechoice == 1){
            if (logged_in->money < 200){
                printf("Uang tidak cukup! Silakan bekerja dulu.\n");
            }
            else{
                tebakAngka(&gamescore);
                logged_in->money = logged_in->money + gamescore - 200;
            }
        }
        else{
            if (logged_in->money < 500){
                printf("Uang tidak cukup! Silakan bekerja dulu.\n");
            }
            else{
                wordl3(&gamescore);
                logged_in->money = logged_in->money + gamescore - 500;
            }
        }
    }
}

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
        STARTWORD(NULL);
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
        STARTWORD(NULL);
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
void Remove (ListDin *list_barang){
    printf("Nama barang yang ingin dihapus: ");
    STARTWORD(NULL);

    Word name;
    name.Length = 0;

    char goods[50] = "";
    int length = 0;

    GoodsWithManyWords(goods, &length, currentWord);
    while (!isEndWord()){
        STARTWORD(NULL);
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

    if (IsMemberListDin(*list_barang, name)){
        Barang tempBarang = makeBarang(0, name);
        int idx = SearchListDin(*list_barang, tempBarang);
        DeleteAtListDin(list_barang, idx);
        printf("\"%s\" telah dihapus dari toko.\n", name.TabWord);
    }
    else{
        printf("Barang tidak ditemukan di toko.\n");
    }
}

//logout
//fungsi logout

//save
void Save(char *filename, List *list_user, ListDin *list_barang) {
    char path[100] = "../save/";
    int idx = 0;
    while (filename[idx] != '\0' && idx < 50) {
        path[8 + idx] = filename[idx];
        idx++;
    }
    path[8 + idx] = '\0';

    system("mkdir save >nul 2>nul");


    FILE *file = fopen(path, "r");
    if (file != NULL) {
        fclose(file);
        printf("File '%s' sudah ada. Apakah ingin di-overwrite? (y/n): ", filename);
        STARTWORD(NULL);
        if (!IsWordEqual(currentWord, "Y") && !IsWordEqual(currentWord, "y")){
            printf("Proses dibatalkan.\n");
            return;
        }
        system("mkdir save >nul 2>nul");
    }

    file = fopen(path, "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file '%s'.\n", filename);
        return;
    }

    fprintf(file, "%d\n", list_barang->Neff);

    for (int i = 0; i < list_barang->Neff; i++) {
        ElTypeBarang barang = list_barang->A[i];
        fprintf(file, "%d %s\n", barang.price, barang.name);
    }

    fprintf(file, "%d", Length(*list_user));

    for (int i = 0; i < Length(*list_user); i++) {
        fprintf(file, "\n", list_barang->Neff);
        ElTypeUser user = list_user->A[i];
        fprintf(file, "%d %s %s", user.money, user.name, user.password);
    }

    fclose(file);
    printf("Data berhasil disimpan ke %s\n", path);
}

//quit
void Quit(List *list_user, ListDin *list_barang, boolean *running){
    char filename[50];

    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    STARTWORD(NULL);

    if (IsWordEqual(currentWord, "Y") || IsWordEqual(currentWord, "y")){
        printf("Tuliskan nama file tempat kamu ingin menyimpan: ");
        STARTWORD(NULL);

        CopyString(filename, currentWord.TabWord); 

        Save(filename, list_user, list_barang);

        printf("Kamu keluar dari PURRMART. \nDadah ^_^/\n");
        *running = false;
    } 
    else{
        printf("Data sesi tidak disimpan. Tetap keluar (Y/N)? ");
        STARTWORD(NULL);
        if (IsWordEqual(currentWord, "Y") || IsWordEqual(currentWord, "y")){
            *running = false;
        }
    }
}

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
        printf("USER KOSONG!\n\n");
    } else {
        printf("ISI USER:\n");
        printf("========================================================================================================================\n");
        printf("| %-50s | %-50s | %-10s |\n", "Username", "Password", "Money");
        printf("========================================================================================================================\n");

        for (IdxType i = FirstIdx(list_user); i <= LastIdx(list_user); i++) {
            printf("| %-50s | %-50s | %-10d |\n", list_user.A[i].name, list_user.A[i].password, list_user.A[i].money);
        }

        printf("========================================================================================================================\n\n");
    }
}