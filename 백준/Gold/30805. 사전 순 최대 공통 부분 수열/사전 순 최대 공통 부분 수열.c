#include <stdio.h>

int N, M, A[100], B[100];
int aLeft = 0, bLeft = 0;

_Bool check(int k) {
    for (int i = aLeft; i < N; ++i) {
        if (A[i] == k) {
            for (int j = bLeft; j < M; ++j) {
                if (B[j] == k) {
                    aLeft = i+1;
                    bLeft = j+1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) scanf("%d", &B[i]);

    int ans[100], p = 0;
    for (int i = 100; i >= 1;) {
        if (check(i)) ans[p++] = i;
        else i--;
    }

    printf("%d\n", p);
    for (int i = 0; i < p; ++i) printf("%d ", ans[i]);

    return 0;
}