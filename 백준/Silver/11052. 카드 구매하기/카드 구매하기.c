#include <stdio.h>

int main() {
    int N, P[1001], cost[1001] = {};
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", P+i), cost[i] = P[i];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (cost[i-j] + P[j] > cost[i]) cost[i] = cost[i-j] + P[j];
        }
    }
    printf("%d", cost[N]);
}