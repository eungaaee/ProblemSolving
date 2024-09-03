#include <stdio.h>

int N, S[20][20], sum, min = 0x7fffffff;
_Bool v[20];

int getDiff() {
    int stat = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (v[i] & v[j]) stat += S[i][j];
            else if (!v[i] & !v[j]) stat -= S[i][j];

    return stat < 0 ? -stat : stat;
}

void backtrack(int cnt, int nxtI) {
    if (cnt == N/2) {
        int diff = getDiff();
        if (diff < min) min = diff;
        return;
    }

    for (int i = nxtI; i < N; i++) {
        v[i] = 1;
        backtrack(cnt+1, i+1);
        v[i] = 0;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &S[i][j]);

    backtrack(0, 0);
    printf("%d", min);

    return 0;
}