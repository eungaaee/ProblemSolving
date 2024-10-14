#include <stdio.h>
#include <memory.h>

const int INF = 0x3f3f3f3f;

static inline int min(int a, int b) { return a < b ? a : b; }

int strength[5][5] = {
    {0, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1}
};
int memo[100001][5][5];

int main() {
    memset(memo, 0x3f, sizeof(memo));
    memo[0][0][0] = 0;
    int cnt = 0;
    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;
        cnt++;

        for (int l = 0; l <= 4; l++) { // 0부터 하는 이유는 게임 시작을 (0, 0)에서 하기 때문
            for (int r = 0; r <= 4; r++) {
                if (memo[cnt-1][l][r] >= INF) continue;

                if (memo[cnt-1][l][r] + strength[r][n] < memo[cnt][l][n])
                    memo[cnt][l][n] = memo[cnt-1][l][r] + strength[r][n];
                if (memo[cnt-1][l][r] + strength[l][n] < memo[cnt][n][r])
                    memo[cnt][n][r] = memo[cnt-1][l][r] + strength[l][n];
            }
        }
    }

    int ans = INF;
    for (int l = 0; l <= 4; l++) {
        for (int r = 0; r <= 4; r++) {
            if (memo[cnt][l][r] < ans) {
                ans = memo[cnt][l][r];
            }
        }
    }
    printf("%d", ans);

    return 0;
}