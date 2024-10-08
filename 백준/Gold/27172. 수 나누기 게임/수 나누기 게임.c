#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *x, *score;
    _Bool *isCardExist;

    scanf("%d", &N);

    x = (int *)malloc(N*4);
    score = (int *)calloc(1000001, 4);
    isCardExist = (_Bool *)calloc(1000001, 1);

    for (int i = 0; i < N; i++) {
        scanf("%d", x+i);
        isCardExist[x[i]] = 1;
    }

    for (int i = 0; i < N; i++) {
        int cur = x[i];

        for (int j = cur*2; j <= 1000000; j += cur)
            if (isCardExist[j]) score[cur]++, score[j]--;
    }

    for (int i = 0; i < N; i++) printf("%d ", score[x[i]]);

    free(x);
    free(score);
    free(isCardExist);

    return 0;
}