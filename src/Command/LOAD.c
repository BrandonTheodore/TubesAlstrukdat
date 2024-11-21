#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkarakter.c"
#include "LOAD.h"

FILE* file;
boolean load;

void LOAD(char txt[50]){
    load = true;
    file = fopen(txt, "r");
}