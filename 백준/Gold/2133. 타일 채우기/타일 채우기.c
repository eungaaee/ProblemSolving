// 1 0 3 0 11 0 ...
#include <stdio.h>

int main() {
    int N, dp[31] = {1, 0, 3, 0};
    scanf("%d", &N);
    for (int i = 4; i <= N; i += 2)
        dp[i] = 4*dp[i-2] - dp[i-4];
    printf("%d", dp[N]);
    return 0;
}