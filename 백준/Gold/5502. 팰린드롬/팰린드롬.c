#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

char str[5001];
int memo[5000][5000];

int dp(int L, int R) {
    if (L >= R) return 0;
    else if (memo[L][R]) return memo[L][R];

    if (str[L] == str[R]) memo[L][R] = dp(L+1, R-1);
    else memo[L][R] = min(dp(L, R-1), dp(L+1, R)) + 1; // dp(L, R-1) ==  str[R]을 왼쪽 끝에 붙일 때, dp(L+1, R) == str[L]을 오른쪽 끝에 붙일 때

    return memo[L][R];
}

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", str);

    printf("%d", dp(0, N-1));

    return 0;
}