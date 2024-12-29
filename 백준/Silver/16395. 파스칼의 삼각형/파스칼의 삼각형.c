#include <stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int pyramid[30][30] = {};

    for (int i = 0; i < 30; i++) {
        pyramid[i][0] = 1;
    }

    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= i; j++) {
            pyramid[i][j] = pyramid[i-1][j-1] + pyramid[i-1][j];
        }
    }

    printf("%d", pyramid[n-1][k-1]);

    return 0;
}