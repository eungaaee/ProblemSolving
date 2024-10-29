#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int arr[5001];
int memo[5001][5001];

int dp(int L, int R) {
    if (L >= R) return 0;
    else if (memo[L][R]) return memo[L][R];
    else if (arr[L] == arr[R]) memo[L][R] = dp(L+1, R-1);
    else memo[L][R] = min(dp(L, R-1), dp(L+1, R)) + 1;

    return memo[L][R];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) scanf("%d", arr+i);

    printf("%d", dp(1, N));

    return 0;
}