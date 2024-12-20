#include <stdio.h>
#include "map.h"
#include "ADT/custom/custom.h"

int main() {
    Map keranjang;
    CreateEmptyMap(&keranjang);

    // Menambahkan barang ke keranjang
    Word nama1 = {"Beras", 5};
    Word nama2 = {"Gula", 4};
    Word nama3 = {"Minyak Goreng", 13};

    keytype barang1 = makeBarang(14000, nama1);
    keytype barang2 = makeBarang(5000, nama2);
    keytype barang3 = makeBarang(15000, nama3);

    printf("Menambahkan barang ke keranjang...\n");
    InsertMap(&keranjang, barang1, 5);
    InsertMap(&keranjang, barang2, 2);
    InsertMap(&keranjang, barang3, 1);

    printf("\nMenampilkan isi keranjang:\n");
    DisplayMap(keranjang);

    // Menambahkan barang yang sudah ada
    printf("Menambahkan barang yang sudah ada (Beras, jumlah tambahan 3)...\n");
    InsertMap(&keranjang, barang1, 3);

    printf("\nMenampilkan isi keranjang:\n");
    DisplayMap(keranjang);

    // Menghapus barang
    printf("Menghapus barang (Gula)...\n");
    DeleteMap(&keranjang, barang2);

    printf("\nMenampilkan isi keranjang:\n");
    DisplayMap(keranjang);

    // Mengecek apakah barang ada di keranjang
    printf("Mengecek keberadaan barang:\n");
    printf("- Apakah Beras ada? %s\n", IsMemberMap(keranjang, barang1) ? "Ya" : "Tidak");
    printf("- Apakah Gula ada? %s\n", IsMemberMap(keranjang, barang2) ? "Ya" : "Tidak");

    // Mencari jumlah barang tertentu
    printf("\nJumlah Beras di keranjang: %d\n", ValueMap(keranjang, barang1));
    printf("Jumlah Gula di keranjang: %d\n", ValueMap(keranjang, barang2));

    // Menampilkan keranjang kosong
    printf("\nMenghapus semua barang dari keranjang...\n");
    while (!IsEmptyMap(keranjang)) {
        DeleteMap(&keranjang, keranjang.Elements[0].Barang);
    }

    printf("\nMenampilkan isi keranjang:\n");
    DisplayMap(keranjang);

    printf("=== Pengujian selesai ===\n");

    return 0;
}