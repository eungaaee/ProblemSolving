#include <stdio.h>

int N, M, seq[8], p;

void rec() {
    if (p == M) {
        for (int i = 0; i < M; i++) printf("%d ", seq[i]);
        putchar('\n');
        return;
    }
    for (int i = 1; i <= N; i++) {
        seq[p++] = i;
        rec();
        p--;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    rec();
    return 0;
}