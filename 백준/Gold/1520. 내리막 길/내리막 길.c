#include <stdio.h>
#include <memory.h>

int M, N, map[500][500];
int memo[500][500];

const int d[] = {0, 0, -1, 1};
int dfs(int r, int c) {
    if (r == M-1 && c == N-1) return 1;
    else if (memo[r][c] >= 0) return memo[r][c];
    else {
        memo[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + d[i], nc = c + d[3-i];

            if (0 <= nr && nr < M && 0 <= nc && nc < N) {
                if (map[nr][nc] >= map[r][c]) continue;
                memo[r][c] += dfs(nr, nc);
            }
        }
        return memo[r][c];
    }
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", map[i]+j);
        }
    }

    memset(memo, -1, 250000 * sizeof(int));
    printf("%d", dfs(0, 0));

    return 0;
}