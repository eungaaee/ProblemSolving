#include <stdio.h>

int grid[9][9];
_Bool row[9][10], col[9][10], square[9][10];

static inline void printGrid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", grid[i][j]);
        }
        putchar('\n');
    }
}

_Bool backtrack(int cell) {
    if (cell == 81) {
        printGrid();
        return 1;
    }
    int r = cell/9, c = cell%9;

    if (grid[r][c]) return backtrack(cell+1);
    else {
        for (int i = 1; i <= 9; i++) {
            if (row[r][i] || col[c][i] || square[r/3*3 + c/3][i]) continue;
            row[r][i] = col[c][i] = square[r/3*3 + c/3][i] = 1;
            grid[r][c] = i;
            if (backtrack(cell+1)) return 1;
            row[r][i] = col[c][i] = square[r/3*3 + c/3][i] = grid[r][c] = 0;
        }
    }

    return 0;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%1d", &grid[i][j]);
            if (!grid[i][j]) continue;
            row[i][grid[i][j]] = col[j][grid[i][j]] = square[i/3*3 + j/3][grid[i][j]] = 1;
        }
    }

    backtrack(0);
    
    return 0;
}