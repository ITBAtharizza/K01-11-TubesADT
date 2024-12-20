#include "biological_leakage.h"
#include <stdio.h>

int NeedlemanWunsch(char seq1[], int len1, char seq2[], int len2) {
    int dp[MAX_SEQ_LEN + 1][MAX_SEQ_LEN + 1];
    for (int i = 0; i <= len1; i++) dp[i][0] = i * -1;
    for (int j = 0; j <= len2; j++) dp[0][j] = j * -1;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0);
            int delete = dp[i - 1][j] - 1;
            int insert = dp[i][j - 1] - 1;
            dp[i][j] = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
        }
    }
    return dp[len1][len2];
}

boolean CheckBiologicalLeakage(char seq1[], int len1, char seq2[], int len2) {
    int score = NeedlemanWunsch(seq1, len1, seq2, len2);
    int threshold = 0.8 * (len1 > len2 ? len1 : len2);
    return score >= threshold;
}
