#include <stdio.h>
#include "listdin.h"

int main() {
    /* Membuat listdin */
    ListDin list = MakeListDin();
    
    printf("ListDin di buat.\n");

    /* Mengecek dan memastikan bahwa listdin diawal kosong */
    if (IsEmptyListDin(list)) {
        printf("ListDin is empty.\n");
    }

    /* Membuat beberapa user untuk mengisi list */
    Word nama1 = {"Platypus Laser", 14};
    int harga1 = 10000;
    Barang barang1 = makeBarang(harga1, nama1);

    Word nama2 = {"Shrink Ray", 10};
    int harga2 = 5000;
    Barang barang2 = makeBarang(harga2, nama2);

    Word nama3 = {"Net Shooter", 11};
    int harga3 = 2500;
    Barang barang3 = makeBarang(harga3, nama3);


    /* Menambah elemen ke dalam list */
    InsertFirstListDin(&list, barang1);
    InsertLastListDin(&list, barang3);
    InsertAtListDin(&list, barang2, 1);

    printf("Setelah penambahan elemen:\n");
    PrintListDin(list);

    /* Menghapus elemen dari dalam list */
    DeleteFirstListDin(&list);
    printf("List setelah menghapus elemen pertama:\n");
    PrintListDin(list);

    DeleteLastListDin(&list);
    printf("List setelah menghapus elemen terakhir:\n");
    PrintListDin(list);

    /* Mencari elemen di dalam list */
    SearchListDin(list, barang1);
    if (SearchListDin(list, barang1) == -1) {
        printf("Platypus Laser tidak terdapat pada list.\n");
    }

    /* Menyalin list */
    ListDin copyList = CopyListDin(list);
    printf("List hasil copy:\n");
    PrintListDin(copyList);

    DeallocateListDin(&list);
    DeallocateListDin(&copyList);
    
    return 0;
}
