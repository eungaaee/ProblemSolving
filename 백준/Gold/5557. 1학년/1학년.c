#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int seq[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", seq+i);
    }

    long long dp[N][21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 20; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][seq[0]] = 1;

    for (int i = 1; i < N-1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i-1][j] > 0) {
                if (j + seq[i] <= 20)
                    dp[i][j + seq[i]] += dp[i-1][j];
                if (j - seq[i] >= 0)
                    dp[i][j - seq[i]] += dp[i-1][j];
            }
        }
    }

    printf("%lld", dp[N-2][seq[N-1]]);

    return 0;
}