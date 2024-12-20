#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SEQ_LENGTH 50

int NeedlemanWunsch(char *seq1, char *seq2, int match, int mismatch, int gap) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) dp[i][0] = i * gap;
    for (int j = 0; j <= len2; j++) dp[0][j] = j * gap;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int score = (seq1[i - 1] == seq2[j - 1]) ? match : mismatch;
            dp[i][j] = dp[i - 1][j - 1] + score;
            if (dp[i][j] < dp[i - 1][j] + gap) dp[i][j] = dp[i - 1][j] + gap;
            if (dp[i][j] < dp[i][j - 1] + gap) dp[i][j] = dp[i][j - 1] + gap;
        }
    }

    printf("Matriks Alignment:\n");
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }

    int finalScore = dp[len1][len2];
    for (int i = 0; i <= len1; i++) free(dp[i]);
    free(dp);

    return finalScore;
}

void DetectBiologicalLeakage(char *reference, char *query) {
    int lenRef = strlen(reference);
    int lenQuery = strlen(query);

    if (lenRef > MAX_SEQ_LENGTH || lenQuery > MAX_SEQ_LENGTH) {
        printf("Sekuens terlalu panjang! Maksimum adalah %d karakter.\n", MAX_SEQ_LENGTH);
        return;
    }

    int score = NeedlemanWunsch(reference, query, 1, 0, -1);
    double threshold = 0.8 * ((lenRef > lenQuery) ? lenRef : lenQuery);

    printf("Skor Alignment: %d\n", score);
    printf("Threshold: %.2f\n", threshold);

    if (score >= threshold) {
        printf("Ada kebocoran senjata biologis.\n");
    } else {
        printf("Tidak ada kebocoran senjata biologis.\n");
    }
}
