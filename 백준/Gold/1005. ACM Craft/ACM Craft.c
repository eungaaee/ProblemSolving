#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int N, *D, *memo;
_Bool **order;

int dfs(int cur) {
    if (memo[cur] > -1) return memo[cur];

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (order[i][cur])
            if (dfs(i) > max) max = memo[i];
    }

    return memo[cur] = max + D[cur];
}

int main() {
    int T, K;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &N, &K);

        D = (int *)malloc(N*4 + 4);
        order = (_Bool **)malloc(N*8 + 8);
        for (int i = 1; i <= N; i++) order[i] = (_Bool *)calloc(N+1, 1);

        for (int i = 1; i <= N; i++) scanf("%d", D+i);

        for (int i = 0, x, y; i < K; i++) {
            scanf("%d%d", &x, &y);
            order[x][y] = 1;
        }

        int W;
        scanf("%d", &W);

        memo = (int *)malloc(N*4 + 4);
        memset(memo, -1, N*4 + 4);
        printf("%d\n", dfs(W));

        for (int i = 1; i <= N; i++) free(order[i]);
        free(order);
        free(D);
        free(memo);
    }

    return 0;
}