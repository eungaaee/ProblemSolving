#include <stdio.h>

int main() {
    int N, dp[10], ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < 10; i++) dp[i] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 9; j > 0; j--)
            for (int k = 0; k < j; k++) dp[j] += dp[k], dp[j] %= 10007;
    for (int i = 0; i < 10; i++) ans += dp[i], ans %= 10007;
    printf("%d", ans);
    return 0;
}