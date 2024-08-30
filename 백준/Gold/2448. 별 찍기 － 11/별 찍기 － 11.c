#include <stdio.h>

char grid[3072][6144];

void star(int r, int c, int size) {
    if (size == 3) {
        grid[r][c]
        = grid[r+1][c-1] = grid[r+1][c+1]
        = grid[r+2][c-2] = grid[r+2][c-1] = grid[r+2][c] = grid[r+2][c+1] = grid[r+2][c+2]
        = '*';
        return;
    }

    star(r, c, size/2);
    star(r+size/2, c-size/2, size/2);
    star(r+size/2, c+size/2, size/2);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N*2; j++) {
            grid[i][j] = ' ';
        }
    }

    star(0, N-1, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N*2; j++) {
            printf("%c", grid[i][j]);
        }
        putchar('\n');
    }
}