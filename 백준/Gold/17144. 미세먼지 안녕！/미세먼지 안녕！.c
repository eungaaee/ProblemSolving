#include <stdio.h>
#include <stdlib.h>

int R, C, T;
int **A, **deltaA;

void spread() {
    int d[4] = {0, 0, -1, 1};

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            deltaA[i][j] = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (A[r][c] / 5 > 0) {
                int spreadCnt = 0;

                for (int i = 0; i < 4; i++) {
                    int nr = r + d[i], nc = c + d[3-i];
                    if (0 <= nr && nr < R && 0 <= nc && nc < C && A[nr][nc] > -1) {
                        deltaA[nr][nc] += A[r][c] / 5;
                        spreadCnt++;
                    }
                }

                deltaA[r][c] -= A[r][c] / 5 * spreadCnt;
            }
        }
    }

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            A[r][c] += deltaA[r][c];
}

void airPurifier(int row) {
    for (int r = row-2; r > 0; r--) A[r][0] = A[r-1][0];
    for (int c = 1; c < C; c++) A[0][c-1] = A[0][c];
    for (int r = 1; r < row; r++) A[r-1][C-1] = A[r][C-1];
    for (int c = C-1; c > 1; c--) A[row-1][c] = A[row-1][c-1];
    A[row-1][1] = 0;

    for (int r = row+2; r < R; r++) A[r-1][0] = A[r][0];
    for (int c = 1; c < C; c++) A[R-1][c-1] = A[R-1][c];
    for (int r = R-1; r > row; r--) A[r][C-1] = A[r-1][C-1];
    for (int c = C-1; c > 1; c--) A[row][c] = A[row][c-1];
    A[row][1] = 0;
}

int main() {
    scanf("%d%d%d", &R, &C, &T);

    A = (int **)malloc(8 * R);
    deltaA = (int **)malloc(8 * R);

    int apRow;
    for (int i = 0; i < R; i++) {
        A[i] = (int *)malloc(4 * C);
        deltaA[i] = (int *)malloc(4 * C);

        for (int j = 0; j < C; j++) scanf("%d", A[i]+j);

        if (A[i][0] < 0) apRow = i;
    }

    while (T--) {
        spread();
        airPurifier(apRow);
    }

    int dust = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[i][j] > 0) dust += A[i][j];
        }
    }

    printf("%d", dust);

    for (int i = 0; i < R; i++) free(A[i]);
    free(A);

    return 0;
}