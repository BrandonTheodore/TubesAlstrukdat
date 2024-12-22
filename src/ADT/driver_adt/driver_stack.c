#include <stdio.h>
#include "../master_header_adt.h"

void printStack(Stack S) {
    if (IsEmptyStack(S)) {
        printf("Stack kosong\n");
        return;
    }
    printf("Isi Stack:\n");
    for (int i = Top(S); i >= 0; i--) {
        printf("[%d] Total Harga: %d\n", i, S.T[i].totalHarga);
    }
    printf("Total Biaya Stack: %d\n\n", S.totalBiaya);
}

int main() {
    Stack S;
    infotypeStack item;
    
    printf("1. Tes CreateEmptyStack dan IsEmptyStack:\n");
    CreateEmptyStack(&S);
    printf("Stack kosong? %s\n\n", IsEmptyStack(S) ? "Ya" : "Tidak");

    printf("2. Tes PushStack:\n");
    item.totalHarga = 5000;
    PushStack(&S, item);
    printf("Push item harga 5000\n");
    
    item.totalHarga = 7000;
    PushStack(&S, item);
    printf("Push item harga 7000\n");
    printStack(S);

    printf("3. Tes PopStack:\n");
    PopStack(&S, &item);
    printf("Item yang di-pop: %d\n", item.totalHarga);
    printStack(S);

    // Cleanup
    printf("4. Cleanup Stack:\n");
    while (!IsEmptyStack(S)) {
        PopStack(&S, &item);
    }
    CreateEmptyStack(&S);
    printf("Stack kosong setelah cleanup? %s\n", IsEmptyStack(S) ? "Ya" : "Tidak");

    return 0;
}