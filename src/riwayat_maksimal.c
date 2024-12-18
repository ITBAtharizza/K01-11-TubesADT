#include "riwayat_maksimal.h"

void RiwayatMaksimal(char *history[], int historyCount, Map *M) {
    if (historyCount == 0) {
        printf("Belum ada riwayat pembelian.\n");
        return;
    }

    char *maxItem = history[0];
    int maxValue = 0;

    for (int i = 0; i < historyCount; i++) {
        for (int j = 0; j < M->Count; j++) {
            if (IsSameString(history[i], M->Elements[j].Key)) {
                if (M->Elements[j].Value > maxValue) {
                    maxValue = M->Elements[j].Value;
                    maxItem = history[i];
                }
            }
        }
    }

    printf("Item dengan riwayat maksimal adalah %s dengan nilai %d.\n", maxItem, maxValue);
}
