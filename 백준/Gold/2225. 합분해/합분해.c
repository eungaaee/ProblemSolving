#include <stdio.h>

int main() {
    int N, K, C[201][201] = {};
    scanf("%d%d", &N, &K);

    for (int i = 0; i <= N; i++) C[1][i] = 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                C[i][j] += C[i-1][k];
                C[i][j] %= 1000000000;
            }
        }
    }
    printf("%d", C[K][N]);
    return 0;
}