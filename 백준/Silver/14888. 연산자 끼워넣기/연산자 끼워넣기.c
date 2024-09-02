#include <stdio.h>
#define INF 0x3f3f3f3f

int N, A[11], plus, minus, multiply, divide, max = -INF, min = INF;

void backtrack(int res, int idx) {
    if (idx == N) {
        if (res > max) max = res;
        if (res < min) min = res;
        return;
    }
    if (plus) plus--, backtrack(res + A[idx], idx+1), plus++;
    if (minus) minus--, backtrack(res - A[idx], idx+1), minus++;
    if (multiply) multiply--, backtrack(res * A[idx], idx+1), multiply++;
    if (divide) divide--, backtrack(res / A[idx], idx+1), divide++;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A+i);
    scanf("%d%d%d%d", &plus, &minus, &multiply, &divide);

    backtrack(A[0], 1);
    printf("%d\n%d", max, min);

    return 0;
}