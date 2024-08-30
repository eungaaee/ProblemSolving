#include <stdio.h>

int main() {
    int N, T[16] = {}, P[16] = {}, cost[16] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d%d", T+i, P+i);

    int max = 0;
    for (int i = 0; i <= N; i++) {
        if (max > cost[i]) cost[i] = max;
        if (i+T[i] <= N && cost[i] + P[i] > cost[i+T[i]]) cost[i+T[i]] = cost[i] + P[i];
        if (cost[i] > max) max = cost[i];
    }
    printf("%d", max);
    return 0;
}