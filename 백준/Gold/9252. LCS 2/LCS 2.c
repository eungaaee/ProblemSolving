#include <stdio.h>
#define max(a, b) a > b ? a : b

char A[1001], B[1001];
int dp[1002][1002];

void findLCS(int i, int j) {
    if (i == 0 || j == 0) return;
    if (dp[i][j] == dp[i-1][j]) findLCS(i-1, j);
    else if (dp[i][j] == dp[i][j-1]) findLCS(i, j-1);
    else {
        findLCS(i-1, j-1);
        printf("%c", A[i-1]);
    }
}

int main() {
    scanf("%s%s", A, B);

    int ALen = 0, BLen = 0;
    for (int i = 0; A[i] != '\0'; i++) ALen++;
    for (int i = 0; B[i] != '\0'; i++) BLen++;

    for (int i = 1; i <= ALen; i++) {
        for (int j = 1; j <= BLen; j++) {
            if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    printf("%d\n", dp[ALen][BLen]);
    findLCS(ALen, BLen);

    return 0;
}