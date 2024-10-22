#include <stdio.h>

int lower_bound(int *arr, int size, int target) {
    int l = 0, r = size, m;

    while (l < r) {
        m = l + (r-l)/2;
        if (arr[m] < target) l = m+1;
        else r = m;
    }

    return l;
}

int main() {
    int N;
    scanf("%d", &N);

    int A_i, arr[N+1], len = 0;
    arr[0] = -0x3f3f3f3f;

    for (int i = 0; i < N; i++) {
        scanf("%d", &A_i);

        if (A_i == arr[len]) continue;
        else if (A_i > arr[len]) arr[++len] = A_i;
        else arr[lower_bound(arr, len, A_i)] = A_i; // lower_bound -> 현재 A보다 큰 수 중에서 가장 왼쪽 수의 위치 얻기
    }

    printf("%d", len);

    return 0;
}