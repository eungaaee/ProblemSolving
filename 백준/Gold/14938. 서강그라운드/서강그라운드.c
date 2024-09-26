#include <stdio.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f

static inline void floyd_warshall(int n, int **dist) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);

    int *t, **dist;
    t = (int *)malloc(4 * (n+1));
    dist = (int **)malloc(8 * (n+1));
    for (int i = 1; i <= n; i++) {
        dist[i] = (int *)malloc(4 * (n+1));
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) scanf("%d", t+i);

    for (int i = 0; i < r; i++) {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);

        dist[a][b] = dist[b][a] = l;
    }

    floyd_warshall(n, dist);

    int maxSum = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) sum += t[j];
        }
        if (maxSum < sum) maxSum = sum;
    }
    printf("%d", maxSum);

    free(t);
    for (int i = 0; i <= n; i++) free(dist[i]);
    free(dist);

    return 0;
}