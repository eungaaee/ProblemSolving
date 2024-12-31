// N - 가장 긴 증가하는 부분 수열의 길이
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int children[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", children+i);
    }

    // LIS
    int dp[N];
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (children[j] < children[i]) {
                if (dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }

    int longest = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > longest)
            longest = dp[i];
    }
    
    printf("%d", N - longest);

    return 0;
}