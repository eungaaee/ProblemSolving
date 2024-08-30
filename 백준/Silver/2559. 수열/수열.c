#include <stdio.h>

int main() {
    int N, K, seq[100001];
    scanf("%d%d", &N, &K);
    seq[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", seq+i);
        seq[i] = seq[i-1] + seq[i];
    }
    int max = seq[K];
    for (int i = K+1; i <= N; i++) if (seq[i] - seq[i-K] > max) max = seq[i] - seq[i-K];
    printf("%d", max);
    return 0;
}