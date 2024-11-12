#include <stdio.h>
#define INF 1e9

int main() {
    int V, E;
    scanf("%d%d", &V, &E);

    int cost[V+1][V+1];
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            cost[i][j] = INF;

    for (int i = 0, from, to; i < E; i++) {
        scanf("%d%d", &from, &to);
        scanf("%d", cost[from] + to);
    }

    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    int minCycle = INF;
    for (int i = 1; i <= V; i++) {
        if (cost[i][i] < minCycle)
            minCycle = cost[i][i];
    }
    printf("%d", minCycle < INF ? minCycle : -1);

    return 0;
}