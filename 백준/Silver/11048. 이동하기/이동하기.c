#include <stdio.h>

static inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int N, M, candy[2][1001] = {}, cur;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &candy[i%2][j]);
            candy[i%2][j] += max(candy[i%2][j-1], candy[(i+1)%2][j]);
        }
    }
    printf("%d", candy[(N+1)%2][M]);
    return 0;
}