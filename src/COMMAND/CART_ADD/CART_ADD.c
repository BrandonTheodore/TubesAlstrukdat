#include <stdio.h>
#include "cart_add.h"

void CART_ADD(char *itemName, int quantity) {
    User *user = &userList.A[IDX];
    int idx = SearchArrayDin(AD, itemName);

    if (idx == -1) {
        printf("Barang tidak ada di toko!\n");
    }

    if (IsMemberMap(user->keranjang, itemName)) {
        int index = idxMap(user->keranjang, itemName);
        user->keranjang.Elements[index].Value += quantity;
        printf("%s sebanyak %d ditambahkan ke keranjang\n", itemName, quantity);
    } else {
        InsertMap(&user->keranjang, itemName, quantity);
        printf("%s sebanyak %d ditambahkan ke keranjang\n", itemName, quantity);
    }
}