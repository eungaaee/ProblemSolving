#include <stdio.h>
#define INF 0x7FFFFFFF

struct rc {
    int r, c;
};

char board[10][10];

void backtrack(struct rc red, struct rc blue, int move, int *minMove) {
    static int d[4] = {0, 0, -1, 1};

    if (move > 10) return;

    for (int i = 0; i < 4; i++) {
        // 파란색 시뮬레이션
        struct rc nextBlue = blue;
        while (board[nextBlue.r + d[i]][nextBlue.c + d[3-i]] == '.') {
            nextBlue.r += d[i];
            nextBlue.c += d[3-i];
        }
        if (board[nextBlue.r + d[i]][nextBlue.c + d[3-i]] == 'O') continue; // 구멍에 파란색이 들어가면 실패

        // 빨간색 시뮬레이션
        struct rc nextRed = red;
        while (board[nextRed.r + d[i]][nextRed.c + d[3-i]] == '.') {
            nextRed.r += d[i];
            nextRed.c += d[3-i];
        }
        if (board[nextRed.r + d[i]][nextRed.c + d[3-i]] == 'O') { // 구멍에 파란색이 안 들어갔고 빨간색이 들어가면 성공
            if (move < *minMove) *minMove = move;
            return; // 현재 move 수에서 성공을 확인했으므로 더 확인할 필요 없음
        }

        // 둘 다 구멍에 들어가지 않았다면 원래 위치를 비교해서 겹치지 않도록 처리하고 다음 재귀로 보내기
        if (nextBlue.r == nextRed.r && nextBlue.c == nextRed.c) {
            switch (i) {
                case 0: // 오른쪽으로 기울였다면
                    if (red.c < blue.c) nextRed.c--;
                    else nextBlue.c--;
                    break;
                case 1: // 왼쪽으로 기울였다면
                    if (red.c < blue.c) nextBlue.c++;
                    else  nextRed.c++;
                    break;
                case 2: // 위쪽으로 기울였다면
                    if (red.r < blue.r) nextBlue.r++;
                    else nextRed.r++;
                    break;
                case 3: // 아래쪽으로 기울였다면
                    if (red.r < blue.r) nextRed.r--;
                    else nextBlue.r--;
                    break;
            }
        }
        // printf("\nmove\n%d\n\ni\n%d\n\nR\n%d %d\nB\n%d %d\n", move, i, nextRed.r, nextRed.c, nextBlue.r, nextBlue.c);
        backtrack(nextRed, nextBlue, move+1, minMove);
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    struct rc initRed, initBlue;

    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < M; j++) {
            board[i][j] = getchar();
            if (board[i][j] == 'R') {
                initRed = (struct rc){i, j};
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                initBlue = (struct rc){i, j};
                board[i][j] = '.';
            }
        }
    }

    /* for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
    printf("%d, %d\n%d, %d\n", initRed.r, initRed.c, initBlue.r, initBlue.c); */

    int minMove = INF;
    backtrack(initRed, initBlue, 1, &minMove);
    printf("%d", minMove < INF ? minMove : -1);

    return 0;
}