#include <stdio.h>
#define MOD 1000000000

// length, stair_num, visited
int memo[101][10][1<<10]; // (1<<10) - 1 => 1 *9개 비트

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i <= 9; i++) memo[1][i][1<<i] = 1;

    for (int len = 2; len <= N; len++) {
        for (int num = 0; num <= 9; num++) {
            for (int visited = 0; visited < (1<<10); visited++) {
                if (num > 0) memo[len][num][visited | 1<<num] =
                                (memo[len][num][visited | 1<<num] + memo[len-1][num-1][visited]) % MOD;
                if (num < 9) memo[len][num][visited | 1<<num] = 
                                (memo[len][num][visited | 1<<num] + memo[len-1][num+1][visited]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int num = 1; num <= 9; num++) ans = (ans + memo[N][num][(1<<10)-1]) % MOD;
    printf("%d", ans);

    return 0;
}