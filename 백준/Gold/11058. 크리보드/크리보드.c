#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long dp[N];
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i-1] + 1;
        for (int j = 3; j < i; j++) {
            if (dp[i-j] * (j-1) > dp[i]) {
                dp[i] = dp[i-j] * (j-1);
            }
        }
    }
    
    printf("%lld", dp[N-1]);

    return 0;
}