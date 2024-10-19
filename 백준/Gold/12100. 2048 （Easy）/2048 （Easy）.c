#include <stdio.h>

int N;
enum DIRECTION {UP, DOWN, LEFT, RIGHT};

int find_maximum_cell(int (*grid)[20]) {
    int max = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] > max) max = grid[r][c];
        }
    }
    return max;
}

void backtrack(enum DIRECTION d, int move, int (*board)[20], int *maxCell) {
    if (move == 5) {
        int gridMaxCell = find_maximum_cell(board);
        if (gridMaxCell > *maxCell) *maxCell = gridMaxCell;
        return;
    }

    int copy[20][20] = {};

    switch (d) {
        case UP:
            for (int c = 0; c < N; c++) {
                int prev = -1, ptr = 0;
                for (int r = 0; r < N; r++) {
                    if (board[r][c] == 0) continue;

                    if (prev == -1) prev = board[r][c];
                    else if (prev == board[r][c]) copy[ptr++][c] = board[r][c] * 2, prev = -1;
                    else copy[ptr++][c] = prev, prev = board[r][c];
                }
                if (prev != -1) copy[ptr][c] = prev;
            }
            break;
        case DOWN:
            for (int c = 0; c < N; c++) {
                int prev = -1, ptr = N-1;
                for (int r = N-1; r >= 0; r--) {
                    if (board[r][c] == 0) continue;
                    
                    if (prev == -1) prev = board[r][c];
                    else if (prev == board[r][c]) copy[ptr--][c] = board[r][c] * 2, prev = -1;
                    else copy[ptr--][c] = prev, prev = board[r][c];
                }
                if (prev != -1) copy[ptr][c] = prev;
            }
            break;
        case LEFT:
            for (int r = 0; r < N; r++) {
                int prev = -1, ptr = 0;
                for (int c = 0; c < N; c++) {
                    if (board[r][c] == 0) continue;

                    if (prev == -1) prev = board[r][c];
                    else if (prev == board[r][c]) copy[r][ptr++] = board[r][c] * 2, prev = -1;
                    else copy[r][ptr++] = prev, prev = board[r][c];
                }
                if (prev != -1) copy[r][ptr] = prev;
            }
            break;
        case RIGHT:
            for (int r = 0; r < N; r++) {
                int prev = -1, ptr = N-1;
                for (int c = N-1; c >= 0; c--) {
                    if (board[r][c] == 0) continue;

                    if (prev == -1) prev = board[r][c];
                    else if (prev == board[r][c]) copy[r][ptr--] = board[r][c] * 2, prev = -1;
                    else copy[r][ptr--] = prev, prev = board[r][c];
                }
                if (prev != -1) copy[r][ptr] = prev;
            }
            break;
    }

    for (int i = 0; i < 4; i++) backtrack(i, move+1, copy, maxCell);
}

int main() {
    scanf("%d", &N);

    int board[20][20];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", board[i]+j);
    
    int max = 0;
    for (int i = 0; i < 4; i++) backtrack(i, 0, board, &max);
    printf("%d", max);

    return 0;
}