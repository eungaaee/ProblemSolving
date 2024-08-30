#include <stdio.h>

int main() {
    int N, d;
    long long route[100][100] = {1};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &d);
            if (i == N-1 && j == N-1) break;
            route[i][j+d] += route[i][j];
            route[i+d][j] += route[i][j];
        }
    }
    printf("%lld", route[N-1][N-1]);
    return 0;
}