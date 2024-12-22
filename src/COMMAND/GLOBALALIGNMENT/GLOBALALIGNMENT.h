#include <stdio.h>
#include <stdlib.h>
#include "../master_header_command.h"

#ifndef GLOBALALIGNMENT_H
#define GLOBALALIGNMENT_H

#define MAX_LENGTH 51  // maksimum 50 karakter + 1 untuk null terminator
#define MATCH 1
#define MISMATCH 0
#define GAP -1

void needleman_wunsch(char *seq1, char *seq2, int len1, int len2, int *final_score, char *aligned_seq1, char *aligned_seq2);
void check_leakage();

#endif