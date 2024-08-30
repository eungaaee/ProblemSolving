#include <stdio.h>

int ops[1000001][2];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) ops[i][0] = 0x3f3f3f3f;
    for (int i = 1; i < N; i++) {
        if (i*3 <= N && ops[i][0]+1 < ops[i*3][0]) ops[i*3][0] = ops[i][0]+1, ops[i*3][1] = i;
        if (i*2 <= N && ops[i][0]+1 < ops[i*2][0]) ops[i*2][0] = ops[i][0]+1, ops[i*2][1] = i;
        if (ops[i][0]+1 < ops[i+1][0]) ops[i+1][0] = ops[i][0]+1, ops[i+1][1] = i;
    }

    printf("%d\n", ops[N][0]);
    int idx = N;
    while (idx >= 1) {
        printf("%d ", idx);
        idx = ops[idx][1];
    }
    return 0;
}