#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", A+i);
    }
    qsort(A, N, sizeof(int), compare);

    int ans = 0x7FFFFFFF;
    int left = 0, right = 0;
    while (right < N) {
        if (A[right] - A[left] < M) right++;
        else {
            if (A[right] - A[left] < ans) {
                ans = A[right] - A[left];
            }
            left++;
        }
    }

    printf("%d", ans);

    return 0;
}