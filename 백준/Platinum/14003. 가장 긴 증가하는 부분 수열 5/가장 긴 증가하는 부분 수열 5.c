#include <stdio.h>

int lower_bound(const int *const arr, const int size, const int target) {
    int l = 0, r = size, m;
    while (l < r) {
        m = l + (r-l>>1);
        if (arr[m] < target) l = m+1;
        else r = m;
    }

    return l;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N+1];
    int dp[N+1], len = 0;
    dp[0] = -1000000001;
    int ori_to_dp[N+1]; // ori_to_dp[i] = 원본 수열의 i번째 수가 dp의 몇 번째 인덱스로 들어갔는지 (i >= 1)
    for (int i = 1; i <= N; i++) ori_to_dp[i] = -1;

    for (int i = 1; i <= N; i++) {
        scanf("%d", A+i);

        if (A[i] == dp[len]) continue;
        else if (A[i] > dp[len]) {
            dp[++len] = A[i];
            ori_to_dp[i] = len;
        } else {
            int idx = lower_bound(dp, len, A[i]); // 현재 수보다 큰 수 중에서 가장 작은 수 위치로
            dp[idx] = A[i];
            ori_to_dp[i] = idx;
        }
    }

    printf("%d\n", len);

    int stack[len], stackIdx = 0;

    for (int i = N; i >= 1; i--)
        if (ori_to_dp[i] == len) stack[stackIdx++] = A[i], len--;

    while (--stackIdx >= 0) printf("%d ", stack[stackIdx]);
    
    return 0;
}