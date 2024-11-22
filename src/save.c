#include "save.h"

void save(char *filename, List *list_user, ListDin *list_barang) {
    char path[100] = "./save/";
    int idx = 0;
    while (filename[idx] != '\0' && idx < 50) {
        path[7 + idx] = filename[idx];
        idx++;
    }
    path[7 + idx] = '\0';

    if (system("mkdir -p ./save") != 0) {
        printf("Error: Tidak dapat membuat folder.\n");
        return;
    }

    FILE *file = fopen(path, "r");
    if (file != NULL) {
        fclose(file);
        printf("File '%s' sudah ada. Apakah ingin di-overwrite? (y/n): ", filename);
        char response;
        scanf(" %c", &response);
        if (response != 'y') {
            printf("Proses dibatalkan.\n");
            return;
        }
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

    fprintf(file, "%d\n", Length(*list_user));

    for (int i = 0; i < lLength(*list_user); i++) {
        ElTypeUser user = list_user->A[i];
        fprintf(file, "%d %s %s\n", user.money, user.name, user.password);
    }

    fclose(file);
    printf("Data berhasil disimpan ke %s\n", path);
}