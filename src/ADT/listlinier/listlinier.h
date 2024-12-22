#ifndef LISTLINIER_H
#define LISTLINIER_H

#include "../boolean.h"
#include "../mesinkata/mesinkata.h"
#define NilList NULL

typedef char* infotypelist;
typedef struct tElmtList *address_list;
typedef struct tElmtList {
    infotypelist Info;
    address_list Next;
} ElmtList;
typedef struct {
    address_list First;
} Listlinier;

// Macros
#define First(L) ((L).First)
#define Info(P) (P->Info)
#define Next(P) (P->Next)

boolean IsEmptyLinier(Listlinier L);
void CreateEmptyLinier(Listlinier *L);
address_list AlokasiLinier(infotypelist X);
void DealokasiLinier(address_list *P);
address_list SearchLinier(Listlinier L, infotypelist X);
void InsVFirstLinier(Listlinier *L, infotypelist X);
void InsVLastLinier(Listlinier *L, infotypelist X);
void DelVFirstLinier(Listlinier *L, infotypelist *X);
void DelVLastLinier(Listlinier *L, infotypelist *X);
void InsertFirstLinier(Listlinier *L, address_list P);
void InsertAfterLinier(Listlinier *L, address_list P, address_list Prec);
void InsertLastLinier(Listlinier *L, address_list P);
void DelFirstLinier(Listlinier *L, address_list *P);
void DelPLinier(Listlinier *L, infotypelist X);
void DelLastLinier(Listlinier *L, address_list *P);
void DelAfterLinier(Listlinier *L, address_list *Pdel, address_list Prec);
void PrintInfoLinier(Listlinier L);
int NbElmtLinier(Listlinier L);
void InversLinier(Listlinier *L);
void Konkat1Linier(Listlinier *L1, Listlinier *L2, Listlinier *L3);

#endif