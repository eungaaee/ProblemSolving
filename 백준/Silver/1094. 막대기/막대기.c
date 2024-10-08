// 64 32 16 8 4 2 1
#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int mask = 1, cnt = 0;

    for (int i = 0; i < 7; i++) {
        if (X & mask) cnt++;
        mask <<= 1;
    }

    printf("%d", cnt);

    return 0;
}