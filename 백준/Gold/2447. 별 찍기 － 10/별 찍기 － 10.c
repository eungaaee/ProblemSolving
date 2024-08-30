#include <stdio.h>

void star(int r, int c, int size) {
    if ((r / size) % 3 == 1 && (c / size) % 3 == 1) putchar(' ');
    else if (size / 3 > 0) star(r, c, size / 3);
    else putchar('*');
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            star(i, j, N);
        }
        putchar('\n');
    }

    return 0;
}