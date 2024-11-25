#include <stdio.h>
#include "../List.h"

void printlist(List L) {
    printf("isi list:\n");
    for (int i = 0; i < L.Neff; i++) {
        printf("pengguna %d: nama: %s, password: %s, saldo: %d\n", 
               i+1, L.A[i].name, L.A[i].password, L.A[i].money);
    }
    printf("total pengguna: %d\n", L.Neff);
}

int main() {
    List myList;
    int searchindeks;

    printf("1. Tes MakeList and IsEmpty:\n");
    myList = MakeList();
    if (IsEmpty(myList)) {
        printf("List kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    printf("\n2. Tes InsertLast:\n");
    InsertLast(&myList, "bob", "bob123", 1200);
    InsertLast(&myList, "matt", "hai12", 1500);
    InsertLast(&myList, "carlen", "char789", 2000);
    printlist(myList);

    printf("\n3. Tes Length:\n");
    printf("panjang: %d\n", Length(myList));

    printf("\n4. Tes FirstIdx and LastIdx:\n");
    printf("First indeks: %d\n", FirstIdx(myList));
    printf("Last indeks: %d\n", LastIdx(myList));

    printf("\n5. Tes IsIdxValid and IsIdxEff:\n");

    if (IsIdxValid(myList, 1)) {
        printf("indeks 1 valid\n");
    } else {
        printf("indeks 1 tidak valid\n");
    }

    if (IsIdxValid(myList, 100)) {
        printf("indeks 100 valid\n");
    } else {
        printf("indeks 100 tidak valid\n");
    }

    if (IsIdxEff(myList, 1)) {
        printf("indeks 1 efektif\n");
    } else {
        printf("indeks 1 tidak efektif\n");
    }

    if (IsIdxEff(myList, 3)) {
        printf("indeks 3 efektif\n");
    } else {
        printf("indeks 3 tidak efektif\n");
    }

    printf("\n6. Tes Search:\n");
    if (Search(myList, "Bob", &searchindeks)) {
        printf("Bob berada pada indeks: %d\n", searchindeks);
    } else {
        printf("Bob tidak ditemukan\n");
    }
    if (Search(myList, "carlen", &searchindeks)) {
        printf("carlen berada pada indeks: %d\n", searchindeks);
    } else {
        printf("carlen tidak ditemukan\n");
    }

    return 0;
}
