#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    long long dist[N-1], cost[N];
    for (int i = 0; i < N-1; i++) scanf("%lld", &dist[i]);
    for (int i = 0; i < N; i++) scanf("%lld", &cost[i]);

    long long curCost = cost[0], ans = curCost * dist[0];
    for (int i = 1; i < N-1; i++) {
        if (curCost > cost[i]) curCost = cost[i];
        ans += curCost * dist[i];
    }
    printf("%lld", ans);
    return 0;
}