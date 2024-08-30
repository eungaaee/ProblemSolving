#include <stdio.h>

int memo[1001][1001];

int c(int n, int k) {
    if (memo[n][k]) return memo[n][k];
    if (n == k || k == 0) return 1;
    return memo[n][k] = (c(n-1, k-1)%10007 + c(n-1, k)%10007)%10007;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    printf("%d", c(N, K));
    return 0;
}