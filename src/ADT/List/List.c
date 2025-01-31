#include <stdio.h>
#include "list.h"

List MakeList() {
    List L;
    for (int i = 0; i < MaxEl; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            L.A[i].name[j] = Mark;
            L.A[i].password[j] = Mark;
            L.A[i].nickname[j] = Mark;
        }
        L.A[i].money = 0;
        L.A[i].umur = 0;
    }
    L.Neff = 0;
    return L;
}

boolean IsEmpty(List L) {
    return L.Neff == 0;
}

int Length(List L) {
    return L.Neff;
}

int FirstIdx(List L) {
    return 0;
}

int LastIdx(List L) {
    return L.Neff - 1;
}

boolean IsIdxValid(List L, int i) {
    return (i >= 0 && i < MaxEl);
}

boolean IsIdxEff(List L, int i) {
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}

boolean Search(List L, char name[], int *index) {
    boolean found = false;
    int i = 0;
    
    while (i < L.Neff && !found) {
        if (strlength(L.A[i].name) == strlength(name)) {
            boolean match = true;
            for (int j = 0; j < strlength(name); j++) {
                if (L.A[i].name[j] != name[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                found = true;
                *index = i;
            }
        }
        i++;
    }
    return found;
}

void InsertLast(List *userlist, User user) {
    if (userlist->Neff < MaxEl) {
        userlist->A[userlist->Neff] = user; 
        userlist->Neff++;
    }
}