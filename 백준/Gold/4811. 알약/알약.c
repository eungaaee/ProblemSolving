#include <stdio.h>

int main() {
    long long dp[31][31] = {}; // dp[w][h]
    for (int i = 1; i <= 30; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = i; j <= 30; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    while (1) {
        int N;
        scanf("%d", &N);

        if (N == 0) break;
        else printf("%lld\n", dp[N][N]);
    }

    return 0;
}