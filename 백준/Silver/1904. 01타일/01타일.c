#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int dp[N];
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < N; i++) dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    printf("%d", dp[N-1]);
    return 0;
}