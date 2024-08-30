#include <stdio.h>

int main() {
    int N, A[1001], L[1001];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", A+i);

    for (int i = 1; i <= N; i++) {
        L[i] = 1;
        for (int j = 1; j < i; j++) {
            if (A[j] > A[i] && L[j]+1 > L[i]) L[i] = L[j]+1;
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++)
        if (L[i] > max) max = L[i];
    printf("%d", max);
    return 0;
}