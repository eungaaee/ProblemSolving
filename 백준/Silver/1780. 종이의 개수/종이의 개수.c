#include <stdio.h>

int paper[2187][2187]; // = 3^7
int count[3]; // 0: -1, 1: 0, 2: 1

_Bool isSame(int r, int c, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (paper[r][c] != paper[r+i][c+j]) return 0;
    return 1;
}

void split(int r, int c, int size) {
    if (isSame(r, c, size)) count[paper[r][c]+1]++;
    else {
        int nextSize = size/3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                split(r + nextSize*i, c + nextSize*j, nextSize);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &paper[i][j]);

    split(0, 0, N);
    printf("%d\n%d\n%d", count[0], count[1], count[2]);

    return 0;
}