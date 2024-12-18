/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef LIST_H
#define LIST_H

#include "../boolean.h"
#include "../custom.h"

#define MaxEl 100
#define MAX_LEN 50
#define Mark '\0'

typedef struct {
    User A[MaxEl];
    int Neff;
} List;

extern List userList; 

List MakeList();
boolean IsEmpty(List L);
int Length(List L);
int FirstIdx(List L);
int LastIdx(List L);
boolean IsIdxValid(List L, int i);
boolean IsIdxEff(List L, int i);
boolean Search(List L, char X[MAX_LEN], int* idx);
void InsertLast(List *L, User user);

#endif