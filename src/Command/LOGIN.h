#ifndef LOGIN_H
#define LOGIN_H

#include "boolean.h"

#define CAPACITY 50

extern boolean login;

typedef struct
{
    char user[CAPACITY];
    char pass[CAPACITY];
} UPass;

#endif