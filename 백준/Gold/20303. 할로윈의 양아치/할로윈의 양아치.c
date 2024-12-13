#include <stdio.h>

int parent[30001];

int Find(int x) {
    if (parent[x] != x) return parent[x] = Find(parent[x]);
    else return parent[x];
}

void Unify(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y) parent[y] = x;
    else if (x > y) parent[x] = y;
    else return;
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);

    for (int i = 1; i <= N; i++) parent[i] = i;

    int candy[N+1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", candy+i);
    }

    for (int i = 0, a, b; i < M; i++) {
        scanf("%d%d", &a, &b);
        Unify(a, b);
    }

    int child_count[N+1];
    for (int i = 1; i <= N; i++) child_count[i] = 1;

    for (int i = 1; i <= N; i++) {
        if (parent[i] != i) {
            int p = Find(i);
            candy[p] += candy[i];
            child_count[p] += child_count[i]; // += 1
        }
    }

    int dp[K];
    for (int i = 0; i < K; i++) dp[i] = 0;

    for (int i = 1; i <= N; i++) {
        if (parent[i] != i) continue;
        
        for (int j = K-1; j - child_count[i] >= 0; j--) {
            if (dp[j - child_count[i]] + candy[i] > dp[j])
                dp[j] = dp[j - child_count[i]] + candy[i];
        }
    }

    printf("%d", dp[K-1]);

    return 0;
}