#include "list.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
List MakeList() {
    List L;
    for (int i = 0; i < MaxEl; i++) {
        L.A[i] = Mark;
    }
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmpty(List L) {
    return L.A[0] == Mark;
}

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i) {
    return L.A[i];
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v) {
    L->A[i] = v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L) {
    int count = 0;
    while (count < MaxEl && L.A[count] != Mark) {
        count++;
    }
    return count;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L) {
    return 0;
}

IdxType LastIdx(List L) {
    return Length(L) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(List L, IdxType i) {
    return (i >= 0 && i < MaxEl);
}

boolean IsIdxEff(List L, IdxType i) {
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X) {
    for (IdxType i = FirstIdx(L); i <= LastIdx(L); i++) {
        if (L.A[i] == X) {
            return true;
        }
    }
    return false;
}

void InsertFirst(List *L, ElType X) {
    if (Length(*L) < MaxEl) {
        for (int i = Length(*L); i > 0; i--) {
            L->A[i] = L->A[i-1];
        }
        L->A[0] = X;
    }
}

void InsertAt(List *L, ElType X, IdxType i) {
    if (Length(*L) < MaxEl && IsIdxEff(*L, i)) {
        for (int j = Length(*L); j > i; j--) {
            L->A[j] = L->A[j-1];
        }
        L->A[i] = X;
    }
}

void InsertLast(List *L, ElType X) {
    if (Length(*L) < MaxEl) {
        L->A[Length(*L)] = X;
    }
}

void DeleteFirst(List *L) {
    if (!IsEmpty(*L)) {
        for (int i = 0; i < Length(*L) - 1; i++) {
            L->A[i] = L->A[i+1];
        }
        L->A[Length(*L) - 1] = Mark;
    }
}

void DeleteAt(List *L, IdxType i) {
    if (IsIdxEff(*L, i)) {
        for (int j = i; j < Length(*L) - 1; j++) {
            L->A[j] = L->A[j+1];
        }
        L->A[Length(*L) - 1] = Mark;
    }
}

void DeleteLast(List *L) {
    if (!IsEmpty(*L)) {
        L->A[LastIdx(*L)] = Mark;
    }
}

List Concat(List L1, List L2) {
    List L;
    int i = 0;
    
    // Copy L1 to L
    while (i < Length(L1)) {
        L.A[i] = L1.A[i];
        i++;
    }

    // Copy L2 to L
    for (int j = 0; j < Length(L2); j++) {
        L.A[i] = L2.A[j];
        i++;
    }

    // Fill remaining elements with Mark
    for (int j = i; j < MaxEl; j++) {
        L.A[j] = Mark;
    }

    return L;
}

int findUsername(char nama[MAX_LEN], List data) {
    for(int i = 0; i < MAX_LEN; i++) {
        if(isEqual(data.TotUs[i].name, nama)) {
            return i; 
        }
    }
    return -1;  // 
}


