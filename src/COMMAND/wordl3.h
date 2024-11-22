#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "list.h"
#include "saldo.h"

#ifndef WORDL3_H
#define WORDL3_H

#define MAX_ATTEMPTS_W 5
#define NMax 50 
#define W_COST 500

boolean isWordEqual(Word word1, Word word2);
boolean isValidWord(Word guess);
void readGuess(Word *guess);
void compareGuess(Word guess, Word secretWord, Word *result);
void displayPreviousGuesses(Word results[], int attempts);
void playWordle();

#endif