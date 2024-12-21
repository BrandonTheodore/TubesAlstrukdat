#ifndef MAP_H
#define MAP_H

#include "../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../dynamiclist/dynamiclist.h" 

#define NilMap 0
#define MaxElMap 100


typedef char* keytype;
typedef int valuetype;
typedef int address_map;

typedef struct {
    keytype Key;
    valuetype Value;
} ElmtMap;

typedef struct {
    ElmtMap Elements[MaxElMap];
    int Count;
} Map;

extern Map store;

// Macros
#define Count(M) (M).Count
#define Elements(M) (M).Elements

// Function Prototypes
boolean IsEmptyMap(Map M);
void CreateEmptyMap(Map *M);
void InsertMap(Map *M, keytype k, valuetype v);
void DeleteMap(Map *M, keytype k);
boolean IsMemberMap(Map M, keytype k);
int idxMap(Map M, keytype k);
int idxMaxValueMap(Map M);

#endif