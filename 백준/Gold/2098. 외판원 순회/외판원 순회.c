#include <stdio.h>
#define INF 1e9

int N, W[16][16];
int cost[16][1<<16]; // cost[a][b] = 현재 방문 상태 비트마스크가 b일 때, a부터 남은 곳을 모두 방문할 때의 최소비용

int tsp(int cur, int visit_bit) {
    if (visit_bit == (1<<N)-1) { // 전부 방문 했다면
        if (W[cur][0]) return W[cur][0]; // 시작점으로 돌아가는 경로가 있으면
        else return INF;
    }
    if (cost[cur][visit_bit] > -1) // 이미 계산 했었다면 (메모이제이션)
        return cost[cur][visit_bit];

    cost[cur][visit_bit] = INF;
    for (int i = 0; i < N; i++) {
        if (visit_bit & (1<<i)) continue;
        else if (W[cur][i] == 0) continue;
        
        int remainder_search_cost = tsp(i, visit_bit | (1<<i)); 
        if (W[cur][i] + remainder_search_cost < cost[cur][visit_bit]) // (cur to i 비용) + (i부터 남은 곳 모두 방문할 때의 최소비용) or cur부터 남은 곳 모두 방문할 때의 현재비용
            cost[cur][visit_bit] = W[cur][i] + remainder_search_cost;
    }
    return cost[cur][visit_bit];
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", W[i]+j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1<<N); j++) {
            cost[i][j] = -1;
        }
    }

    printf("%d", tsp(0, 1));

    return 0;
}