#include <stdio.h>

char directionMap[1000][1000];
int v[1000][1000]; // 0: not visited, 1: visited, -1: visited and counted

void followMap(int r, int c, int *const ans) {
    if (v[r][c] == 0) {
        v[r][c] = 1;
        switch (directionMap[r][c]) {
            case 'U':
                followMap(r-1, c, ans);
                break;
            case 'D':
                followMap(r+1, c, ans);
                break;
            case 'L':
                followMap(r, c-1, ans);
                break;
            case 'R':
                followMap(r, c+1, ans);
                break;
        }
        v[r][c] = -1;
    } else if (v[r][c] == 1) (*ans)++;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    getchar();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", directionMap[i]+j);
        }
        getchar();
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!v[i][j]) followMap(i, j, &ans);
        }
    }
    printf("%d", ans);

    return 0;
}