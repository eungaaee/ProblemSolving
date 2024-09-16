#include <stdio.h>

int main() {
    int K;
    scanf("%d", &K);

    int A[46] = {[0] = 1}, B[45] = {[0] = 0};

    for (int i = 1; i <= K; i++) {
        A[i] = B[i-1];
        B[i] = A[i-1] + B[i-1];
    }

    printf("%d %d", A[K], B[K]);

    return 0;
}