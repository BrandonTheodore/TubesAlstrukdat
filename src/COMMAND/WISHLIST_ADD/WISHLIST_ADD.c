#include <stdio.h>
#include "wishlist_add.h"


void WISHLIST_ADD() {
    User *user = &userList.A[IDX];

    printf("Masukkan nama barang: ");
    RESETWORD();
    STARTWORD2();
    
    char itemName[MAX_LEN];
    strcopy(currentWord.TabWord, itemName);
    
    if (SearchArrayDin(AD, itemName) == -1) {
        printf("Tidak ada barang dengan nama %s!\n", itemName);
        return;
    }

    address_list P = SearchLinier(user->wishlist, itemName);
    if (P != NilList) {
        printf("%s sudah ada di wishlist!\n", itemName);
        return;
    }

    InsVLastLinier(&user->wishlist, itemName);
    printf("Berhasil menambahkan %s ke wishlist!\n", itemName);
}