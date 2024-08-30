#include <stdio.h>

int main() {
    int n, k, coin[100], dp[10001] = {};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", coin+i);
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++)
            dp[j] += dp[j-coin[i]];
    }
    printf("%d", dp[k]);
    return 0;
}