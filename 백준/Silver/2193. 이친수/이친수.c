#include <stdio.h>

int main() {
    int N;
    long long dp[90] = {1, 1};
    scanf("%d", &N);
    for (int i = 2; i < N; i++) dp[i] = dp[i-1] + dp[i-2];
    printf("%lld", dp[N-1]);
    return 0;
}