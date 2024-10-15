#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, coins[20], M;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", coins+i);
        scanf("%d", &M);

        int dp[10001] = {1};
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= M; j++) {
                if (coins[i] > j) continue;
                dp[j] += dp[j-coins[i]];
            }
        }

        printf("%d\n", dp[M]);
    }

    return 0;
}