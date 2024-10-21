/*
1-N까지 순회하면서
현재 숫자가 이전 숫자보다 크면 그대로 추가,
작으면 현재 숫자보다 큰 수 중에서 가장 작은 수 위치에 대체하기
*/

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
    arr[0] = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &A_i);

        if (A_i == arr[len]) continue;
        else if (A_i > arr[len]) arr[++len] = A_i;
        else arr[lower_bound(arr, len, A_i)] = A_i; // lower_bound -> 현재 A보다 큰 수 중에서 가장 왼쪽 수의 위치 얻기
    }

    printf("%d", len);

    return 0;
}