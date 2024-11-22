#ifndef LOGIN_H
#define LOGIN_H

#include "boolean.h"

#define MAX_LEN 50

extern boolean login;

typedef struct {
char name[MAX_LEN];
char password[MAX_LEN];
int money;
} User;

#endif