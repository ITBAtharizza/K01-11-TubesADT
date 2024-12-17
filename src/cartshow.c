#include "cartshow.h"

void cartshow(ListDin List_Items, Map Cart) {
    if (IsEmptyMap(Cart)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("Berikut adalah isi keranjang belanjamu!\n");
        printf("Kuantitas\t| Nama\t\t| Total\n");
        int totalPrice = 0;
        for (int i = 0; i < Cart.Count; i++) {
            boolean found = false;
            int idxBarang;
            for (int j = 0; j < List_Items.Neff; j++) {
                if (IsSameString(Cart.Elements[i].Key, List_Items.A[j].name)) {
                    found = true;
                    idxBarang = j;
                    break;
                }
            }
            int harga = ((Cart.Elements[i].Value) * List_Items.A[idxBarang].price);
            printf("%d\t| %s\t\t| %d\n", Cart.Elements[i].Value, Cart.Elements[i].Key, harga);
            totalPrice += harga;
        }
        printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalPrice);
    }
}