#include <stdio.h>
#include <stdlib.h>

char **board;
_Bool **v;

int N, M;

void dfs(int r, int c, int prev_r, int prev_c, int k) {
    static int d[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = r + d[i], nc = c + d[3-i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        
        if (nr != prev_r && nc != prev_c && v[nr][nc] && k >= 4) {
            printf("Yes");
            exit(0);
        } else if (!v[nr][nc] && board[nr][nc] == board[r][c]) {
            v[nr][nc] = 1;
            dfs(nr, nc, r, c, k+1);
            v[nr][nc] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);

    board = (int **)malloc(8 * N);
    v = (_Bool **)malloc(8 * N);
    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(M);
        v[i] = (_Bool *)malloc(M);
        for (int j = 0; j < M; j++) {
            scanf(" %c", board[i]+j);
            v[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs(i, j, -1, -1, 1);
        }
    }

    printf("No");

    for (int i = 0; i < N; i++) {
        free(board[i]);
        free(v[i]);
    }
    free(board);
    free(v);
    
    return 0;
}