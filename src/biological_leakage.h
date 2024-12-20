#ifndef BIOLOGICAL_LEAKAGE_H
#define BIOLOGICAL_LEAKAGE_H

#include "boolean.h"

#define MAX_SEQ_LEN 50

int NeedlemanWunsch(char seq1[], int len1, char seq2[], int len2);
boolean CheckBiologicalLeakage(char seq1[], int len1, char seq2[], int len2);

#endif
