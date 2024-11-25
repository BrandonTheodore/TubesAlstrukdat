#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"


#ifndef WORDL3_H
#define WORDL3_H

#define MAX_ATTEMPTS_W 6
#define NMax 50 
#define W_COST 500

boolean isWordEqual(Word word1, Word word2);
boolean isValidWord(Word guess);
void readGuess(Word *guess);
void compareGuess(Word guess, Word secretWord, Word *result);
void displayPreviousGuesses(Word results[], int attempts);
void playWordle();

#endif