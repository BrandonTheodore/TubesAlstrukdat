#include <stdio.h>
#include "../master_header_adt.h"

void printlist(List L) {
    if (IsEmpty(L)) {
        printf("List kosong\n");
        return;
    }
    printf("Isi list:\n");
    for (int i = 0; i < L.Neff; i++) {
        printf("Pengguna %d:\n", i+1);
        printf("Nama: %s\n", L.A[i].name);
        printf("Password: %s\n", L.A[i].password);
        printf("Money: %d\n", L.A[i].money);
    }
    printf("Total pengguna: %d\n", L.Neff);
}

int main() {
    List myList;
    User user;
    int searchindeks;

    printf("1. Tes MakeList dan IsEmpty:\n");
    myList = MakeList();
    if (IsEmpty(myList)) {
        printf("List kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    printf("\n2. Tes InsertLast:\n");
    // User 1
    strcpy(user.name, "bob");
    strcpy(user.password, "bob123");
    user.money = 1200;
    InsertLast(&myList, user);

    // User 2
    strcpy(user.name, "matt");
    strcpy(user.password, "matt123");
    user.money = 1500;
    InsertLast(&myList, user);

    // User 3
    strcpy(user.name, "dar");
    strcpy(user.password, "dar123");
    user.money = 2000;
    InsertLast(&myList, user);

    printlist(myList);

    printf("\n3. Tes Length:\n");
    printf("Panjang list: %d\n", Length(myList));

    printf("\n4. Tes FirstIdx dan LastIdx:\n");
    printf("First Index: %d\n", FirstIdx(myList));
    printf("Last Index: %d\n", LastIdx(myList));

    printf("\n5. Tes IsIdxValid dan IsIdxEff:\n");
    printf("Index 1 valid? %s\n", IsIdxValid(myList, 1) ? "Ya" : "Tidak");
    printf("Index 100 valid? %s\n", IsIdxValid(myList, 100) ? "Ya" : "Tidak");
    printf("Index 1 efektif? %s\n", IsIdxEff(myList, 1) ? "Ya" : "Tidak");
    printf("Index 3 efektif? %s\n", IsIdxEff(myList, 3) ? "Ya" : "Tidak");

    printf("\n6. Tes Search:\n");
    if (Search(myList, "bob", &searchindeks)) {
        printf("bob ditemukan pada index: %d\n", searchindeks);
    } else {
        printf("bob tidak ditemukan\n");
    }

    if (Search(myList, "dar", &searchindeks)) {
        printf("dar ditemukan pada index: %d\n", searchindeks);
    } else {
        printf("dar tidak ditemukan\n");
    }

    if (Search(myList, "john", &searchindeks)) {
        printf("john ditemukan pada index: %d\n", searchindeks);
    } else {
        printf("john tidak ditemukan\n");
    }

    return 0;
}