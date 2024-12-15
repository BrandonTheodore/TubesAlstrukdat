#ifndef STACK_H
#define STACK_H

#include "master_header_adt.h"

// Constants
#define NilStack -1
#define MaxElStack 100

// Type Definitions
typedef struct {
    char* namaBarang;
    int jumlahBarang;
    int totalHarga;
} infotypeStack;

typedef struct {
    infotypeStack T[MaxElStack];
    int Top;
    int totalBiaya;
} Stack;

// Macros
#define Top(S) (S).Top
#define InfoTop(S) (S).T[(S).Top]

// Function Prototypes
boolean IsEmptyStack(Stack S);
void CreateEmptyStack(Stack *S);
void PushStack(Stack *S, infotypeStack X);
void PopStack(Stack *S, infotypeStack *X);

#endif