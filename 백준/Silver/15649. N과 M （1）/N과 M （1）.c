#include <stdio.h>

int N, M;

void rec() {
    static _Bool v[9];
    static int seq[9], p;
    if (p == M) {
        for (int i = 0; i < p; i++) printf("%d ", seq[i]);
        putchar('\n');
        return;
    }
    for (int i = 1; i <= N; i++)
        if (!v[i]) {
            v[i] = 1;
            seq[p++] = i;
            rec();
            v[i] = 0;
            p--;
        }
}

int main() {
    scanf("%d%d", &N, &M);
    rec();
    return 0;
}