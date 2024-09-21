#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *T, *P, *dp;
    scanf("%d", &N);

    T = (int *)malloc(4 * (N+2));
    P = (int *)malloc(4 * (N+2));
    dp = (int *)calloc(N+2, 4);

    for (int i = 1; i <= N; i++) scanf("%d%d", T+i, P+i);

    int maxMoney = 0;
    for (int i = 1; i <= N+1; i++) {
        if (dp[i] > maxMoney) maxMoney = dp[i];

        if (i+T[i] > N+1) continue;
        else if (dp[i+T[i]] < maxMoney + P[i]) dp[i+T[i]] = maxMoney + P[i];
    }

    printf("%d", maxMoney);

    free(T);
    free(P);
    free(dp);
    
    return 0;
}