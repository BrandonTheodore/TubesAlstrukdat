#include <stdio.h>
#include "cart_remove.h"

void CART_REMOVE(char *itemName, int quantity) {
    User *user = &userList.A[IDX];

    boolean found = false;
    int cartQuantity = 0;
    for (int i = 0; i < user->keranjang.Count; i++) {
        if (isEqual(user->keranjang.Elements[i].Key,  itemName)) {
            found = true;
            cartQuantity = user->keranjang.Elements[i].Value;
            break;
        }
    }

    if (!found) {
        printf("Barang tidak ada di keranjang belanja!\n");
        return;
    }

    if (quantity > cartQuantity) {
        printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", 
               cartQuantity, itemName);
        return;
    }

    if (cartQuantity == quantity) {
        DeleteMap(&user->keranjang, itemName);
    } else {
        for (int i = 0; i < user->keranjang.Count; i++) {
            if (isEqual(user->keranjang.Elements[i].Key, itemName)) {
                user->keranjang.Elements[i].Value -= quantity;
                break;
            }
        }
    }

    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, itemName);
}