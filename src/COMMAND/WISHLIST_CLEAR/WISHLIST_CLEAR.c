#include <stdio.h>
#include "wishlist_clear.h"

void WISHLIST_CLEAR() {
    User *user = &userList.A[IDX];
    
    // Delete all nodes
    address_list P;
    while (!IsEmptyLinier(user->wishlist)) {
        DelFirstLinier(&user->wishlist, &P);
        DealokasiLinier(&P);
    }

    // Create new empty list
    CreateEmptyLinier(&user->wishlist);
    
    printf("Wishlist telah dikosongkan.\n");
}