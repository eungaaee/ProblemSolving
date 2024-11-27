#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int N;
    scanf("%d", &N);

    int crane[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", crane+i);
    }

    int M;
    scanf("%d", &M);

    int box[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", box+i);
    }

    qsort(crane, N, sizeof(int), compare);
    qsort(box, M, sizeof(int), compare);

    int count;

    if (crane[N-1] < box[M-1]) count = -1;
    else {
        count = 0;
        int erased = 0;

        while (erased < M) {
            count++;
            int crane_idx = N-1;
            
            for (int i = M-1; i >= 0; i--) {
                if (crane_idx < 0) break;
                else if (box[i] == -1) continue;
                else if (crane[crane_idx] < box[i]) continue;

                box[i] = -1;
                erased++;
                crane_idx--;
            }
        }
    }

    printf("%d", count);

    return 0;
}