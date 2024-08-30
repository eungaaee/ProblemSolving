#include <memory.h>
#include <stdio.h>

int N, K, *A, *tmp;

void merge_sort(int l, int r) {
    if (l >= r || K <= 0) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    merge(l, m, r);
}

void merge(int l, int m, int r) {
    int i = l, j = m + 1, p = 0;
    while (i <= m && j <= r) {
        if (A[i] <= A[j]) tmp[p++] = A[i++];
        else tmp[p++] = A[j++];
    }
    while (i <= m) tmp[p++] = A[i++];
    while (j <= r) tmp[p++] = A[j++];
    p = 0;
    while (l <= r) {
        K--;
        if (K == 0) {
            printf("%d", tmp[p]);
            return;
        }
        A[l++] = tmp[p++];
    }
}

int main() {
    scanf("%d%d", &N, &K);
    A = malloc(N*4);
    tmp = malloc(N*4);
    for (int i = 0; i < N; i++) scanf("%d", A+i);
    merge_sort(0, N - 1);
    if (K > 0) printf("-1");
    free(A), free(tmp);
    return 0;
}