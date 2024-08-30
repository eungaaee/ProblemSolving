#include <stdio.h>

int N, W[10][10], cost, minCost = 0x3f3f3f3f;
_Bool v[10];

void dfs(int cur, int depth) {
    if (depth == N-1) {
        if (W[cur][0]) {
            cost += W[cur][0];
            if (cost < minCost) minCost = cost;
            cost -= W[cur][0];
        }
        return;
    }
    for (int i = 1; i < N; i++) {
        if (v[i] || !W[cur][i]) continue;

        v[i] = 1;
        cost += W[cur][i];
        dfs(i, depth+1);
        v[i] = 0;
        cost -= W[cur][i];
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);

    dfs(0, 0);
    printf("%d", minCost);

    return 0;
}