#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "START.h"

boolean start;
boolean login;
boolean load;
User user;

void MULAI(){
    start = true;
    if(!load){
        LOAD("default.txt");
    }
}