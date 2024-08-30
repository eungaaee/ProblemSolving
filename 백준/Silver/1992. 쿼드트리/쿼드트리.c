#include <stdio.h>

_Bool frame[64][64];

_Bool isSame(int r, int c, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (frame[r][c] != frame[r+i][c+j]) return 0;
    return 1;
}

void split(int r, int c, int size) {
    if (isSame(r, c, size)) printf("%d", frame[r][c]);
    else {
        putchar('(');
        int nextSize = size/2;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                split(r + nextSize*i, c + nextSize*j, nextSize);
        putchar(')');
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &frame[i][j]);

    split(0, 0, N);
    return 0;
}