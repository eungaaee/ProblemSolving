#include <stdio.h>
#define max(a, b, c) a>b?a>c?a:c:b>c?b:c;

int main() {
    int n, grape[10001], dp[10001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", grape+i);

    dp[0] = 0;
    dp[1] = grape[1];
    dp[2] = grape[2] + grape[1];
    for (int i = 3; i <= n; i++) dp[i] = max(dp[i-1], dp[i-2] + grape[i], dp[i-3] + grape[i-1] + grape[i]);

    printf("%d", dp[n]);
    return 0;
}