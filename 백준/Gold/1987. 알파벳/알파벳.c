#include <stdio.h>
#include <stdlib.h>

int R, C, maxCnt = 1;
char **board;

void backtrack(int r, int c, int cnt, _Bool* v) {
    static int d[4] = {0, 0, -1, 1};

    _Bool isMoveable = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + d[i], nc = c + d[3-i];

        if (0 <= nr && nr < R && 0 <= nc && nc < C && !v[board[nr][nc]-'A']) {
            v[board[nr][nc]-'A'] = 1;
            backtrack(nr, nc, cnt+1, v);
            v[board[nr][nc]-'A'] = 0;

            isMoveable = 1;
        }
    }

    if (!isMoveable && cnt > maxCnt) maxCnt = cnt;
}

int main() {
    scanf("%d%d", &R, &C);

    board = (char **)malloc(8 * R);
    for (int i = 0; i < R; i++) {
        board[i] = (char *)malloc(1 * C + 1);
        scanf("%s", board[i]);
    }

    _Bool v[26] = {};
    v[board[0][0]-'A'] = 1;
    backtrack(0, 0, 1, v);

    printf("%d", maxCnt);

    for (int i = 0; i < R; i++) free(board[i]);
    free(board);

    return 0;
}