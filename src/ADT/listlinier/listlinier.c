#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmptyLinier(Listlinier L) {
    return (First(L) == NilList);
}

void CreateEmptyLinier(Listlinier *L) {
    First(*L) = NilList;
}

address_list AlokasiLinier(infotypelist X) {
    address_list P = (address_list)malloc(sizeof(ElmtList));
    if (P != NilList) {
        int len = 0;
        while (X[len] != '\0') {
            len++;
        }
        Info(P) = (char*)malloc((len + 1) * sizeof(char));
        int i = 0;
        while (X[i] != '\0') {
            Info(P)[i] = X[i];
            i++;
        }
        Info(P)[i] = '\0';
        Next(P) = NilList;
    }
    return P;
}

void DealokasiLinier(address_list *P) {
    free(Info((*P)));
    free(*P);
    *P = NilList;
}

address_list SearchLinier(Listlinier L, infotypelist X) {
    address_list P = First(L);
    while (P != NilList) {
        if (isEqual(Info(P), X)) {
            return P;
        }
        P = Next(P);
    }
    return NilList;
}

void InsVFirstLinier(Listlinier *L, infotypelist X) {
    address_list P = AlokasiLinier(X);
    if (P != NilList) {
        InsertFirstLinier(L, P);
    }
}

void InsVLastLinier(Listlinier *L, infotypelist X) {
    address_list P = AlokasiLinier(X);
    if (P != NilList) {
        InsertLastLinier(L, P);
    }
}

void DelVFirstLinier(Listlinier *L, infotypelist *X) {
    address_list P;
    DelFirstLinier(L, &P);
    *X = Info(P);
    DealokasiLinier(&P);
}

void DelVLastLinier(Listlinier *L, infotypelist *X) {
    address_list P;
    DelLastLinier(L, &P);
    *X = Info(P);
    DealokasiLinier(&P);
}

void InsertFirstLinier(Listlinier *L, address_list P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterLinier(Listlinier *L, address_list P, address_list Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastLinier(Listlinier *L, address_list P) {
    if (IsEmptyLinier(*L)) {
        InsertFirstLinier(L, P);
    } else {
        address_list Last = First(*L);
        while (Next(Last) != NilList) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

void DelFirstLinier(Listlinier *L, address_list *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next((*P)) = NULL;
}

void DelPLinier(Listlinier *L, infotypelist X) {
    address_list P = First(*L);
    if (isEqual(Info(P), X)) {
        DelFirstLinier(L, &P);
        DealokasiLinier(&P);
    } else {
        address_list Prec = NilList;
        while (P != NilList && !isEqual(Info(P), X)) {
            Prec = P;
            P = Next(P);
        }
        if (P != NilList) {
            DelAfterLinier(L, &P, Prec);
            DealokasiLinier(&P);
        }
    }
}

void DelLastLinier(Listlinier *L, address_list *P) {
    if (Next(First(*L)) == NilList) {
        DelFirstLinier(L, P);
    } else {
        address_list Prec = NilList;
        address_list Last = First(*L);
        while (Next(Last) != NilList) {
            Prec = Last;
            Last = Next(Last);
        }
        *P = Last;
        Next(Prec) = NilList;
    }
}

void DelAfterLinier(Listlinier *L, address_list *Pdel, address_list Prec) {
    if (Prec != NilList && Next(Prec) != NilList) {  
        *Pdel = Next(Prec);         //
        Next(Prec) = Next((*Pdel));   
        Next((*Pdel)) = NilList;      
    } else {
        *Pdel = NilList;            
    }
}

void PrintInfoLinier(Listlinier L) {
    address_list P = First(L);
    int id=1;
    printf("Berikut adalah isi wishlist: \n");
    while (P != NilList) {
        printf("%d. %s\n", id,Info(P));
        id++;
        P = Next(P);
    }
}

int NbElmtLinier(Listlinier L) {
    int count = 0;
    address_list P = First(L);
    while (P != NilList) {
        count++;
        P = Next(P);
    }
    return count;
}

void InversLinier(Listlinier *L) {
    address_list P = First(*L);
    address_list Prec = NilList;
    address_list Succ;
    while (P != NilList) {
        Succ = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = Succ;
    }
    First(*L) = Prec;
}

void Konkat1Linier(Listlinier *L1, Listlinier *L2, Listlinier *L3) {
    address_list Last1;
    CreateEmptyLinier(L3);
    if (IsEmptyLinier(*L1)) {
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        Last1 = First(*L1);
        while (Next(Last1) != NilList) {
            Last1 = Next(Last1);
        }
        Next(Last1) = First(*L2);
    }
    First(*L1) = NilList;
    First(*L2) = NilList;
}