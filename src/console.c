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

        Word name = MultiWordWord();

        Barang barang = makeBarang(price, name);
        InsertLastListDin(list_barang, barang);
    }

    ADVWORD();
    int jumlah_user = WordToInt(currentWord);

    for (int i = 0; i < jumlah_user; i++){
        Stack riwayat_pembelian;
        CreateEmptyStack(&riwayat_pembelian);

        LinkedList wishlist;
        CreateEmptyLinkedList(&wishlist);

        ADVWORD();
        int money = WordToInt(currentWord);

        ADVWORD();
        Word name;
        CopyString(name.TabWord, currentWord.TabWord);
        name.Length = currentWord.Length;
        
        ADVWORD();
        Word password = currentWord;

        ADVWORD();
        int jumlah_riwayat = WordToInt(currentWord);
        for (int j = 0; j < jumlah_riwayat; j++){
            ADVWORD();
            int total = WordToInt(currentWord);

            Word barang = MultiWordWord();

            OneHistory onehistory;
            onehistory.total = total;
            CopyString(onehistory.name, barang.TabWord);

            PushStack(&riwayat_pembelian, onehistory);
        }
        
        FlipStack(&riwayat_pembelian);

        ADVWORD();
        int jumlah_wishlist = WordToInt(currentWord);
        for (int k = 0; k < jumlah_wishlist; k++){
            Word name = MultiWordWord();
            InsVLastLinkedList(&wishlist, name.TabWord);
        }

        User user = makeUser(money, name, password, riwayat_pembelian, wishlist);
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
void Work(User *user) {
    // daftar pekerjaan yang tersedia
    Job jobs[] = {
        {"Evil Lab Assistant", 100, 14},
        {"OWCA Hiring Manager", 4200, 21},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };
    int jobCount = sizeof(jobs) / sizeof(jobs[0]);

    // menampilkan daftar pekerjaan
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < jobCount; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i + 1, jobs[i].name, jobs[i].income, jobs[i].duration);
    }

    // meng-input pilihan pekerjaan
    printf("Masukkan pekerjaan yang dipilih (1-%d): ", jobCount);
    int choice;
    scanf("%d", &choice);

    // validasi pilihan pekerjaan
    if (choice < 1 || choice > jobCount) {
        printf("Pekerjaan tidak valid!\n");
        return;
    }

    // melakukan pekerjaan
    Job selectedJob = jobs[choice - 1];
    printf("Anda sedang bekerja sebagai %s. Harap tunggu...\n", selectedJob.name);

    clock_t start_time = clock();
    while ((clock() - start_time) < (selectedJob.duration * CLOCKS_PER_SEC)) {}

    // menambahkan pendapatan ke user
    user->money += selectedJob.income;
    printf("Pekerjaan selesai. +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob.income);
}

//work challenge
void WorkChallenge(User *logged_in){
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("3. QUANTUM W0RDL3 (biaya main=500)\n\n");
    printf("Masukan challenge yang hendak dimainkan: ");
    STARTWORD(NULL);
    int gamescore = 0;
    int gamechoice = WordToInt(currentWord);
    if (gamechoice != 1 && gamechoice != 2 && gamechoice != 3){
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
        if (gamechoice == 2){
            if (logged_in->money < 500){
                printf("Uang tidak cukup! Silakan bekerja dulu.\n");
            }
            else{
                wordl3(&gamescore);
                logged_in->money = logged_in->money + gamescore - 500;
            }
        }
        if (gamechoice == 3){
            if (logged_in->money < 500){
                printf("Uang tidak cukup! Silakan bekerja dulu.\n");
            }
            else{
                QuantumWordl3(&gamescore);
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

    CopyString(name.TabWord, goods);
    name.Length = length;

    if (!IsMemberListDin(*list_barang, name)){
        if (!isMemberQueue(*antrian, name)){
            enqueue(antrian, name);
        }
    }
}

//store supply
void Supply(Queue *antrian, ListDin *list_barang){
    if (isEmpty(*antrian)){
        return;
    }
    
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
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", list_barang->A[list_barang->Neff-1].name, list_barang->A[list_barang->Neff-1].price);
        }
    }
    else if (IsWordEqual(currentWord, "Tunda")){
        enqueue(antrian, val);
        printf("%s dikembalikan ke antrian.\n", val.TabWord);
    }
    else if (IsWordEqual(currentWord, "Tolak")){
        printf("%s dihapuskan dari antrian.\n", val.TabWord);
    }
}

//store remove
void Remove(ListDin *list_barang){
    printf("Nama barang yang ingin dihapus: ");
    STARTWORD(NULL);

    Word name;
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

    CopyString(name.TabWord, goods);
    name.Length = length;

    if (IsMemberListDin(*list_barang, name)){
        int idx = IdxMemberListDin(*list_barang, name);
        DeleteAtListDin(list_barang, idx);
        printf("%s telah dihapus dari toko.\n", name.TabWord);
    }
    else{
        printf("Barang tidak ditemukan di toko.\n");
    }
}

//profile
void Profile (User *user) {
    printf("\n+----------------------------------------+\n");
    printf("|             Profil Pengguna            |\n");
    printf("+----------------------------------------+\n");
    printf("| Nama  : %-30s |\n", user->name);
    printf("| Saldo : %-30d |\n", user->money);
    printf("+----------------------------------------+\n");
}

//cart
//cart add
void CartAdd(ListDin *List_Items, Map *Cart) {
    Word name;
    char goods[50] = "";
    int length = 0;

    STARTWORD(NULL);
    do{
        GoodsWithManyWords(goods, &length, currentWord);
        STARTWORD(NULL);
    } while (WordToInt(currentWord) == -9999);

    if (length > 0 && goods[length - 1] == ' '){
        goods[length - 1] = '\0';
        length -= 1;
    }

    if (length > 50){
        length = 50;
    }

    CopyString(name.TabWord, goods);
    name.Length = length;

    int Banyak = WordToInt(currentWord);

    int index = IdxMemberListDin(*List_Items, name);
    if (index == -1) {
        printf("Barang tidak ada di toko!\n");
    } else {
        if (Banyak == 0) {
            printf("Jumlah barang yang dimasukkan ke dalam cart tidak bisa 0!\n");
        } else if (Banyak < 0) {
            printf("Barang yang dimasukkan ke dalam keranjang harus berjumlah positif!\n");
        } else {
            Barang barang = makeBarang(List_Items->A[index].price, name);
            if (IsMemberMap(*Cart, barang)){
                printf("Barang sudah ada!\n");
            }
            else{
                InsertMap(Cart, barang, Banyak);
                printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", Banyak, barang.name);
            }
        }
    }
}

//cart show
void CartShow(Map Cart) {
    if (IsEmptyMap(Cart)) {
        printf("Keranjang kamu kosong!\n");
        return;
    } else {
        int total_biaya = 0;
        printf("================================================================================ \n");
        printf("| %-10s | %-50s | %-10s |\n", "Kuantitas", "Nama Barang", "Total");
        printf("================================================================================ \n");

        for (int i = 0; i < Cart.Count; i++) {
            int total_harga = Cart.Elements[i].Quantity * Cart.Elements[i].Barang.price;
            total_biaya += total_harga;

            printf("| %-10d | %-50s | %-10d |\n", Cart.Elements[i].Quantity, Cart.Elements[i].Barang.name, total_harga);
        }

        printf("================================================================================ \n");
        printf("Total biaya yang harus dikeluarkan adalah %d.\n", total_biaya);
    }
}

void CartRemove(ListDin *List_Items, Map *Cart){
    Word name;
    char goods[50] = "";
    int length = 0;

    STARTWORD(NULL);
    do{
        GoodsWithManyWords(goods, &length, currentWord);
        STARTWORD(NULL);
    } while (WordToInt(currentWord) == -9999);

    if (length > 0 && goods[length - 1] == ' '){
        goods[length - 1] = '\0';
        length -= 1;
    }

    if (length > 50){
        length = 50;
    }

    CopyString(name.TabWord, goods);
    name.Length = length;     

    int Banyak = WordToInt(currentWord);

    int index = IdxMemberListDin(*List_Items, name);
    if (index == -1) {
        printf("Barang tidak ada di toko!\n");
    } else {
        if (Banyak == 0) {
            printf("Jumlah barang yang diremove tidak bisa 0!\n");
        } else if (Banyak < 0) {
            printf("Barang yang diremove harus berjumlah positif!\n");
        } else {
            Barang barang = makeBarang(List_Items->A[index].price, name);
            if (!IsMemberMap(*Cart, barang)){
                printf("Barang tidak ada di keranjang belanja!\n");
            }
            else{
                int quantity = ValueMap(*Cart, barang);
                if (quantity < Banyak){
                    printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", quantity, barang.name);
                }
                else if (quantity == Banyak){
                    DeleteMap(Cart, barang);
                    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", Banyak, barang.name);
                }
                else{
                    int i = 0;
                    boolean found = false;
                    while (!found && i < Cart->Count) {
                        if (IsSameString(Cart->Elements[i].Barang.name, barang.name)) {
                            found = true;
                        } else {
                            i++;
                        }
                    }
                    Cart->Elements[i].Quantity -= Banyak;
                    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", Banyak, barang.name);
                }
            }
        }
    }
}

//wishlist
//wishlist remove ke-i
void WishlistRemoveI(LinkedList *wishlist) {
    STARTWORD(NULL);
    int i = WordToInt(currentWord);

    if (IsEmptyLinkedList(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    if (i < 1) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Posisi tidak valid!\n");
        return;
    }

    address current = First(*wishlist);
    address prev = NULL;
    int idx = 1;

    while (current != NULL && idx < i) {
        prev = current;
        current = Next(current);
        idx++;
    }

    if (current == NULL) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", i);
        return;
    }

    if (prev == NULL) {
        First(*wishlist) = Next(current);
    } else {
        Next(prev) = Next(current);
    }

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i);
    DealokasiLinkedList(&current);
}

//wishlist remove nama
void WishlistRemove(LinkedList *wishlist) {
    Word name;
    char goods[50] = "";
    int length = 0;

    if (IsEmptyLinkedList(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    printf("Masukkan nama barang yang akan dihapus : ");
    STARTWORD(NULL);
    do {
        GoodsWithManyWords(goods, &length, currentWord);
        STARTWORD(NULL);
    } while (WordToInt(currentWord) == -9999);

    CopyString(name.TabWord, goods);
    name.Length = length;

    address current = First(*wishlist);
    address prev = NULL;

    while (current != NULL && !IsSameString(Info(current), name.TabWord)) {
        prev = current;
        current = Next(current);
    }

    if (current == NULL) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", name.TabWord);
        return;
    }

    if (prev == NULL) {
        First(*wishlist) = Next(current);
    } else {
        Next(prev) = Next(current);
    }

    printf("%s berhasil dihapus dari WISHLIST!\n", name.TabWord);
    DealokasiLinkedList(&current);
}

// cart pay
void CartPay(Map *Cart, User *user, Stack *history) {
    if (IsEmptyMap(*Cart)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Kamu akan membeli barang-barang berikut:\n");
    int total_biaya = 0;
    int max_biaya, max_quantity;
    Barang max_barang;
    printf("================================================================================ \n");
    printf("| %-10s | %-50s | %-10s |\n", "Kuantitas", "Nama Barang", "Total");
    printf("================================================================================ \n");

    for (int i = 0; i < Cart->Count; i++) {
        int total_harga = Cart->Elements[i].Quantity * Cart->Elements[i].Barang.price;
        if (i == 0 || max_biaya < total_harga){
            max_biaya = total_harga;
            max_quantity = Cart->Elements[i].Quantity;
            max_barang = Cart->Elements[i].Barang;
        }
        else{
            if (max_biaya == total_harga){
                int whichone = Lexical(max_barang.name, Cart->Elements[i].Barang.name);
                if (whichone == 1){
                    max_barang = Cart->Elements[i].Barang;
                    max_quantity = Cart->Elements[i].Quantity;
                }
            }
        }
        total_biaya += total_harga;
        printf("| %-10d | %-50s | %-10d |\n", Cart->Elements[i].Quantity, Cart->Elements[i].Barang.name, total_harga);
    }

    printf("================================================================================ \n");
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): \n", total_biaya);

    STARTWORD(NULL);
    if (IsWordEqual(currentWord, "Ya")){
        if (total_biaya > user->money){
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", user->money);
            return;
        }
        OneHistory addHistory;
        addHistory.total = max_quantity * max_barang.price;
        CopyString(addHistory.name, max_barang.name);
        PushStack(history, addHistory);
        printf("Selamat kamu telah membeli barang-barang tersebut!\n");
    }
    else if (IsWordEqual(currentWord, "Tidak")){
        printf("Pembelian dibatalkan\n");
    }
    else{
        printf("Input tidak valid. Kembali ke menu utama.\n");
    }
}

//history
void ShowHistory(Stack *history, int line){
    if (IsEmptyStack(*history)){
        printf("Kamu belum membeli barang apapun!\n\n");
        return;
    }

    Stack temp;
    CreateEmptyStack(&temp);
    OneHistory X;

    printf("Riwayat Pembelian:\n");
    printf("============================================================================\n");
    printf("| %-5s | %-50s | %-10s |\n", "No", "Nama Barang", "Harga Total");
    printf("============================================================================\n");

    int i = 1;
    while (!IsEmptyStack(*history) && i < line){
        PopStack(history, &X);
        printf("| %-5d | %-50s | %-10d  |\n", i, X.name, X.total);
        PushStack(&temp, X);
        i++;
    }

    while (!IsEmptyStack(temp)){
        PopStack(&temp, &X);
        PushStack(history, X);
    }

    printf("============================================================================\n\n");    
}

//logout
void Logout(User *logged_in, boolean *log_stats, int *where){
    printf("Selamat Jalan %s!\n", logged_in->name);
    logged_in->name[0] = '\0';
    logged_in->password[0] = '\0';
    logged_in->money = 0;

    *log_stats = false;
    *where = 1;
}

//save
void Save(char *filename, List *list_user, ListDin *list_barang, User *logged_in) {
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
        printf("File '%s' sudah ada. Apakah ingin di-overwrite (Y/N)? ", filename);
        STARTWORD(NULL);
        if (!IsWordEqual(currentWord, "Y") && !IsWordEqual(currentWord, "y")){
            printf("Proses dibatalkan.\n");
            return;
        }
        system("mkdir save >nul 2>nul");
    }

    DumpUser(list_user, logged_in);

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
        fprintf(file, "\n");
        ElTypeUser user = list_user->A[i];
        fprintf(file, "%d %s %s", user.money, user.name, user.password);
    }

    fclose(file);
    printf("Data berhasil disimpan ke %s\n", path);
}

//quit
void Quit(List *list_user, ListDin *list_barang, User *logged_in,boolean *running){
    char filename[50];

    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    STARTWORD(NULL);

    if (IsWordEqual(currentWord, "Y") || IsWordEqual(currentWord, "y")){
        printf("Tuliskan nama file tempat kamu ingin menyimpan: ");
        STARTWORD(NULL);

        CopyString(filename, currentWord.TabWord); 

        Save(filename, list_user, list_barang, logged_in);

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

//bonus
void Bioweapon(Queue *antrian, ListDin *list_barang){
    printf("Masukan nama senjata biologis: ");
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

    CopyString(name.TabWord, goods);

    if (!IsMemberListDin(*list_barang, name)){
        if (!isMemberQueue(*antrian, name)){
            printf("Masukan sekuens DNA: ");
            STARTWORD(NULL);
            Word RNA = DNAToRNA(currentWord);

            printf("Masukan kode rahasia: ");
            STARTWORD(NULL);
            if (IsCode(RNA, currentWord)){
                printf("Senjata biologis mengandung kode, barang akan ditambahkan ke dalam queue!\n\n");
                enqueue(antrian, name);
            }

            else{
                printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n\n");
            }
        }
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
void DisplayUser(List list_user) {
    if (IsEmpty(list_user)) {
        printf("USER KOSONG!\n");
    } else {
        printf("ISI USER:\n");
        for (IdxType i = FirstIdx(list_user); i <= LastIdx(list_user); i++) {
            printf("\n");
            printf("Nama: %s\n", list_user.A[i].name);
            printf("Password: %s\n", list_user.A[i].password);
            printf("Money: %d\n\n", list_user.A[i].money);
            DisplayMap(list_user.A[i].keranjang);
            ShowHistory(&list_user.A[i].riwayat_pembelian, 100);
            PrintInfoLinkedList(list_user.A[i].wishlist);
        }
    }
    printf("\n");
}

Word DNAToRNA(Word DNA){
    Word RNA;
    RNA.Length = DNA.Length;

    for (int i = 0; i < DNA.Length; i++){
        if (DNA.TabWord[i] == 'T'){
            RNA.TabWord[i] = 'A';
        }
        if (DNA.TabWord[i] == 'A'){
            RNA.TabWord[i] = 'U';
        }
        if (DNA.TabWord[i] == 'G'){
            RNA.TabWord[i] = 'C';
        }
        if (DNA.TabWord[i] == 'C'){
            RNA.TabWord[i] = 'G';
        }
    }

    RNA.TabWord[RNA.Length] = '\0';
    return RNA;
}

boolean IsCode(Word RNA, Word Code){
    Word decodedWord;

    int start = 0;
    int modulus = 2;

    while (!IsInString(&decodedWord, &Code)){
        char decoded[50];
        int index = 0;

        for (int i = start; i + 2 < RNA.Length; i++){
            char column[3];
            column[i % 3 - start] = RNA.TabWord[i];
            if (i % 3 == modulus){
                column[3] = '\0';
                Decoding(column, decoded, index);
                index++;
            }
        }
        decoded[index] = '\0';

        CopyString(decodedWord.TabWord, decoded);
        decodedWord.Length = index;

        start++;
        modulus++;
        modulus = modulus % 3;
        
        if (start > 2) {
            break;
        }
    }

    return IsInString(&decodedWord, &Code);
}

void Decoding(char *column, char *decoded, int index){
    column[3] = '\0';
    if (IsSameString(column, "UUU") || IsSameString(column, "UUC")){
        decoded[index] = 'F'; 
    }
    if (IsSameString(column, "UUA") || IsSameString(column, "UUG")){
        decoded[index] = 'L';
    }
    if (IsSameString(column, "UCU") || IsSameString(column, "UCC") || IsSameString(column, "UCA") || IsSameString(column, "UCG")){
        decoded[index] = 'S';
    }
    if (IsSameString(column, "UAU") || IsSameString(column, "UAC")){
        decoded[index] = 'Y';
    }
    if (IsSameString(column, "UAA") || IsSameString(column, "UAG") || IsSameString(column, "UGA")){
        return;
    }
    if (IsSameString(column, "UGU") || IsSameString(column, "UGC")){
        decoded[index] = 'C';
    }
    if (IsSameString(column, "UGG")){
        decoded[index] = 'W';
    }
    if (IsSameString(column, "CUU") || IsSameString(column, "CUC") || IsSameString(column, "CUA") || IsSameString(column, "CUG")){
        decoded[index] = 'L';
    }
    if (IsSameString(column, "CCU") || IsSameString(column, "CCC") || IsSameString(column, "CCA") || IsSameString(column, "CCG")){
        decoded[index] = 'P';
    }
    if (IsSameString(column, "CAU") || IsSameString(column, "CAC")){
        decoded[index] = 'H';
    }
    if (IsSameString(column, "CAA") || IsSameString(column, "CAG")){
        decoded[index] = 'Q';
    }
    if (IsSameString(column, "CGU") || IsSameString(column, "CGC") || IsSameString(column, "CGA") || IsSameString(column, "CGG")){
        decoded[index] = 'R';
    }
    if (IsSameString(column, "AUU") || IsSameString(column, "AUC") || IsSameString(column, "AUA")){
        decoded[index] = 'I';
    }
    if (IsSameString(column, "AUG")){
        decoded[index] = 'M';
    }
    if (IsSameString(column, "ACU") || IsSameString(column, "ACC") || IsSameString(column, "ACA") || IsSameString(column, "ACG")){
        decoded[index] = 'T';
    }
    if (IsSameString(column, "AAU") || IsSameString(column, "AAC")){
        decoded[index] = 'N';
    }
    if (IsSameString(column, "AAA") || IsSameString(column, "AAG")){
        decoded[index] = 'K';
    }
    if (IsSameString(column, "AGU") || IsSameString(column, "AGC")){
        decoded[index] = 'S';
    }
    if (IsSameString(column, "AGA") || IsSameString(column, "AGG")){
        decoded[index] = 'R';
    }
    if (IsSameString(column, "GUU") || IsSameString(column, "GUC") || IsSameString(column, "GUA") || IsSameString(column, "GUG")){
        decoded[index] = 'V';
    }
    if (IsSameString(column, "GCU") || IsSameString(column, "GCC") || IsSameString(column, "GCA") || IsSameString(column, "GCG")){
        decoded[index] = 'A';
    }
    if (IsSameString(column, "GAU") || IsSameString(column, "GAC")){
        decoded[index] = 'D';
    }
    if (IsSameString(column, "GAA") || IsSameString(column, "GAG")){
        decoded[index] = 'E';
    }
    if (IsSameString(column, "GGU") || IsSameString(column, "GGC") || IsSameString(column, "GGA") || IsSameString(column, "GGG")){
        decoded[index] = 'G';
    }
}

boolean IsInString(Word *decoded, Word *code){
    int i, j;

    for (i = 0; i <= decoded->Length - code->Length; i++){
        for (j = 0; j < code->Length; j++){
            if (decoded->TabWord[i + j] != code->TabWord[j]){
                break;
            }
        }
        if (j == code->Length){
            return true;
        }
    }

    return false;
}

void DumpUser(List *list_user, User *logged_in){
    for (int i = 0; i < Length(*list_user); i++){
        if (IsSameString(list_user->A[i].name, logged_in->name) && IsSameString(list_user->A[i].password, logged_in->password)){
            list_user->A[i].money = logged_in->money;
            list_user->A[i].keranjang = logged_in->keranjang;
            list_user->A[i].riwayat_pembelian = logged_in->riwayat_pembelian;
            list_user->A[i].wishlist = logged_in->wishlist;
        }
    }
}

Word MultiWordWord(){
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

    return name;
}

//leksikal
int Lexical(char *str1, char *str2){
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] < str2[i]) return -1;
        else if (str1[i] > str2[i]) return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0') return -1;
    if (str1[i] != '\0' && str2[i] == '\0') return 1;
    return 0;
}