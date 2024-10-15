// 배낭 문제, dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + value[i])
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a > b ? a : b)

int main() {
    int N, M, costSum = 0;
    scanf("%d%d", &N, &M);

    int *m = (int *)malloc((N+1) * sizeof(int));
    int *c = (int *)malloc((N+1) * sizeof(int));

    for (int i = 1; i <= N; i++) scanf("%d", m+i);
    for (int i = 1; i <= N; i++) scanf("%d", c+i), costSum += c[i];

    int **dp = (int **)malloc((N+1) * sizeof(int *));
    for (int i = 0; i <= N; i++) dp[i] = (int *)malloc((costSum+1) * sizeof(int));
    for (int i = 0; i <= N; i++) dp[i][0] = dp[0][i] = 0;

    for (int i = 1; i <= N; i++) { // i번째 앱
        for (int j = 0; j <= costSum; j++) { // 최대 cost가 j일 때
            if (c[i] > j) dp[i][j] = dp[i-1][j]; // i번째 앱을 비활성화하는데 드는 비용이 현재 최대 비용보다 크면
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]] + m[i]); // i번째 앱을 비활성화하지 않으면 dp[i-1][j], 비활성화하면 dp[i-1][j-c[i]] + m[i]
        }
    }

    for (int i = 0; i <= costSum; i++) {
        if (dp[N][i] >= M) {
            printf("%d", i);
            break;
        }
    }

    free(m);
    free(c);
    for (int i = 0; i <= N; i++) free(dp[i]);
    free(dp);

    return 0;
}