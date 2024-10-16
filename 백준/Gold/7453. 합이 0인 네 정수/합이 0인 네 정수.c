#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int lower_bound(int *arr, int size, int target) {
    int l = 0, r = size, m;
    while (l < r) {
        m = l + (r-l)/2;
        if (arr[m] < target) l = m+1;
        else r = m;
    }

    return l;
}

int upper_bound(int *arr, int size, int target) {
    int l = 0, r = size, m;
    while (l < r) {
        m = l + (r-l)/2;
        if (arr[m] <= target) l = m+1;
        else r = m;
    }

    return l;
}

int main() {
    int *A, *B, *C, *D, n;
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));
    B = (int *)malloc(n * sizeof(int));
    C = (int *)malloc(n * sizeof(int));
    D = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", A+i, B+i, C+i, D+i);
    }

    // A[K1] + B[k2] 로 만들어 지는 수들의 배열, C[K1] + D[K2]로 만들어지는 수들의 배열 두 개씩 합쳐서
    int *AB = (int *)malloc(n*n * sizeof(int));
    int *CD = (int *)malloc(n*n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[i*n+j] = A[i] + B[j];
            CD[i*n+j] = C[i] + D[j];
        }
    }

    qsort(AB, n*n, sizeof(int), compare);
    qsort(CD, n*n, sizeof(int), compare);

    long long ans = 0;
    for (int i = 0; i < n*n; i++) {
        // upper_bound - lower_bound
        int target = -AB[i];
        ans += upper_bound(CD, n*n, target) - lower_bound(CD, n*n, target);
    }
    printf("%lld", ans);

    free(A);
    free(B);
    free(C);
    free(D);
    free(AB);
    free(CD);
    A = B = C = D = AB = CD = NULL;

    return 0;
}