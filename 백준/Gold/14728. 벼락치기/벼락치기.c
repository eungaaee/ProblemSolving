#include <stdio.h>

int N, T;
int K[101], S[101]; // 시간,배점
int dp[101][10001];

int main() {
    scanf("%d%d", &N, &T);

    for (int i = 1; i <= N; i++) {
        scanf("%d%d", K+i, S+i);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-K[i] >= 0 && dp[i-1][j-K[i]] + S[i] > dp[i][j]) {
                dp[i][j] = dp[i-1][j-K[i]] + S[i];
            }
        }
    }

    printf("%d", dp[N][T]);
    
    return 0;
}