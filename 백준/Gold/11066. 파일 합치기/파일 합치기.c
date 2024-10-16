// dp[i][j] = dp[i][k] + dp[k+1][j] + i~k의 합 + k+1~j의 합
#include <stdio.h>
#define INF 0x7fffffff

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int K, filePrefixSum[501];

        scanf("%d", &K);
        filePrefixSum[0] = 0;
        for (int i = 1; i <= K; i++) {
            scanf("%d", filePrefixSum+i);
            filePrefixSum[i] += filePrefixSum[i-1];
        }

        int AtoB[501][501] = {};
        for (int len = 1; len < K; len++) {
            for (int i = 1; i+len <= K; i++) {
                AtoB[i][i+len] = INF;
                for (int k = i; k < i+len; k++) {
                    int temp = AtoB[i][k] + AtoB[k+1][i+len] + filePrefixSum[k]-filePrefixSum[i-1] + filePrefixSum[i+len]-filePrefixSum[k];
                    if (temp < AtoB[i][i+len]) AtoB[i][i+len] = temp;
                }
            }
        }

        printf("%d\n", AtoB[1][K]);
    }

    return 0;
}