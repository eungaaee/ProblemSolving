/*
1: 1
2: 2
3: 1+2, 2+1, 3
4: 1+2+1, 1+3, 3+1
5: 2+1+2, 1+3+1, 2+3, 3+2

method[n][i] = 마지막에 i를 사용해서 n을 만드는 경우의 수
method[n][1] = method[n-1][2] + method[n-1][3]
method[n][2] = method[n-2][1] + method[n-2][3]
method[n][3] = method[n-3][1] + method[n-3][2]
*/

#include <stdio.h>
const int MOD = 1e9 + 9;

int main() {
    int T, n;
    scanf("%d", &T);

    int method[100001][4] = {[1][1] = 1, 0, 0, [2][1] = 0, 1, 0, [3][1] = 1, 1, 1};

    for (int i = 4; i <= 100000; i++) {
        method[i][1] = ((long long)method[i-1][2] + method[i-1][3]) % MOD;
        method[i][2] = ((long long)method[i-2][1] + method[i-2][3]) % MOD;
        method[i][3] = ((long long)method[i-3][1] + method[i-3][2]) % MOD;
    }

    while (T--) {
        scanf("%d", &n);
        printf("%d\n", ((long long)method[n][1] + method[n][2] + method[n][3]) % MOD);
    }

    return 0;
}