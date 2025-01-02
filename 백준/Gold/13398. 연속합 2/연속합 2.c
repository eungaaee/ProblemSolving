#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);

    int seq[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", seq+i);
    }

    int ans = seq[0];
    int dp[n][2]; // dp[i][0] = 스킵X, dp[i][1] = 스킵O
    dp[0][0] = dp[0][1] = seq[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0] + seq[i], seq[i]);
        dp[i][1] = max(dp[i-1][1] + seq[i], dp[i-1][0]);

        if (max(dp[i][0], dp[i][1]) > ans) {
            ans = max(dp[i][0], dp[i][1]);
        }
    }

    printf("%d", ans);

    return 0;
}