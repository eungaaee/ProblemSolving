#include <stdio.h>

int main() {
    int N, A[1001];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", A+i);

    int L[1001], R[1001];
    for (int i = 1; i <= N; i++) {
        L[i] = 1;
        for (int j = 1; j < i; j++)
            if (A[i] > A[j] && L[i] < L[j]+1) L[i] = L[j]+1;
    }
    for (int i = N; i >= 1; i--) {
        R[i] = 1;
        for (int j = N; j > i; j--)
            if (A[i] > A[j] && R[i] < R[j]+1) R[i] = R[j]+1;
    }

    int max = 0;
    for (int i = 1; i <= N; i++)
        if (L[i] + R[i] > max) max = L[i] + R[i];
    printf("%d", max-1);
    return 0;
}