#include <stdio.h>

int main() {
    int N, cards[1001], dp[1001];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", cards+i);

    dp[0] = 0;
    for (int i = 1; i <= 1000; i++) dp[i] = 0x3f3f3f3f;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i] > dp[i-j] + cards[j]) dp[i] = dp[i-j] + cards[j];
        }
    }
    printf("%d", dp[N]);
    return 0;
}