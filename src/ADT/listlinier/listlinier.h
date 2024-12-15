#ifndef LISTLINIER_H
#define LISTLINIER_H

#include "master_header_adt.h"

#define NilList NULL

// Type Definitions
typedef char* infotypelist;
typedef struct tElmtList *address_list;
typedef struct tElmtList {
    infotypelist Info;
    address_list Next;
} ElmtList;
typedef struct {
    address_list First;
} List;

// Macros
#define First(L) ((L).First)
#define Info(P) (P->Info)
#define Next(P) (P->Next)

// Function Prototypes
boolean IsEmptyList(List L);
void CreateEmptyList(List *L);
address_list AlokasiList(infotypelist X);
void DealokasiList(address_list *P);
address_list SearchList(List L, infotypelist X);
void InsVFirst(List *L, infotypelist X);
void InsVLast(List *L, infotypelist X);
void DelVFirst(List *L, infotypelist *X);
void DelVLast(List *L, infotypelist *X);
void InsertFirst(List *L, address_list P);
void InsertAfter(List *L, address_list P, address_list Prec);
void InsertLast(List *L, address_list P);
void DelFirst(List *L, address_list *P);
void DelP(List *L, infotypelist X);
void DelLast(List *L, address_list *P);
void DelAfter(List *L, address_list *Pdel, address_list Prec);
void PrintInfo(List L);
int NbElmtList(List L);
void InversList(List *L);
void Konkat1(List *L1, List *L2, List *L3);

#endif