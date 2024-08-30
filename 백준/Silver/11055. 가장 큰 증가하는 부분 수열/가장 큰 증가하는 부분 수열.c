#include <stdio.h>

int main() {
    int N, A[1000], sumA[1000], max;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", A+i);
        sumA[i] = A[i], max = 0;
        for (int j = 0; j < i; j++)
            if (A[j] < A[i] && sumA[j] > max) max = sumA[j];
        sumA[i] += max;
    }

    max = 0;
    for (int i = 0; i < N; i++)
        if (sumA[i] > max) max = sumA[i];
    printf("%d", max);
    return 0;    
}