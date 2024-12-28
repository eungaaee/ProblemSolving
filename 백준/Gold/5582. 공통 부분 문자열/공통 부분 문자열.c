#include <stdio.h>

int dp[4002][4002];

int main() {
    char A[4002], B[4002];
    scanf("%s%s", A+1, B+1);

    int max = 0;
    for (int i = 1; A[i] != '\0'; i++) {
        for (int j = 1; B[j] != '\0'; j++) {
            if (A[i] == B[j]) dp[i][j] = dp[i-1][j-1] + 1;
            if (dp[i][j] > max) max = dp[i][j];
        }
    }
    printf("%d", max);

    return 0;
}