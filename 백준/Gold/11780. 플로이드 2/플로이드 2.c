// 플로이드 워셜 + 경로 기록
#include <stdio.h>
#define INF 1e9
#define MAX_N 100

void find_path(int from, int to, int path_memo[MAX_N+1][MAX_N+1], int *seeker, int *seeker_idx) {
    int via = path_memo[from][to];
    if (via == -1) return;

    find_path(from, via, path_memo, seeker, seeker_idx);
    seeker[(*seeker_idx)++] = via;
    find_path(via, to, path_memo, seeker, seeker_idx);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int cost[MAX_N+1][MAX_N+1], path_memo[MAX_N+1][MAX_N+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = i == j ? 0 : INF;
            path_memo[i][j] = -1;
        }
    }

    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (c < cost[a][b]) cost[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path_memo[i][j] = k;
                }
            }
        }
    }

    // print costs
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", cost[i][j] < INF ? cost[i][j] : 0);
        }
        putchar('\n');
    }

    // print paths
    int seeker[n+1], seeker_idx;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || cost[i][j] == INF) {
                printf("0\n");
                continue;
            }

            seeker_idx = 0;
            seeker[seeker_idx++] = i;
            find_path(i, j, path_memo, seeker, &seeker_idx);
            seeker[seeker_idx++] = j;

            printf("%d ", seeker_idx);
            for (int k = 0; k < seeker_idx; k++)
                printf("%d ", seeker[k]);
            putchar('\n');
        }
    }

    return 0;
}